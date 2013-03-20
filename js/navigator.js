/*
 * Author:  Glavin Wiechert
 * Date:    Tuesday, March 19, 2013
 * 
 */

(function(navigator, undefined) {
  // Public Events
  $(document).ready(function() {


    $(document).on('pagebeforechange', function(e, data) {
      console.log('Page before change: ' + data.toPage);

      // Go to the Module
      navigator.goToModule(data.toPage);

    });

    // Init 
    scobeyConverter.loadMenu();
    scobeyConverter.init();

  });

  // Public methods 
  navigator.goToModule = function(toPage) {
    console.log("goToModule(" + toPage + ")");
    // Check if the module is already loaded
    //$.mobile.changePage("/m/" + moduleAddress); // , {data:{param1:'value1'}}
    //var url = $.url(document.location);
    //var param1 = url.param("param1"); 
    //document.location.hash = moduleAddress;



    // We only want to handle changePage() calls where the caller is
    // asking us to load a page by URL.
    var href = "";
    if (typeof toPage === "string") {
      href = toPage;
      // location.hash = pageName;

      if (href.search("#") != -1) {// Check if it is a module
        href = href.replace(/[^#]*#/, "");
        if (!href) {
          //link was an empty hash meant purely
          //for interaction, so we ignore it.
          event.preventDefault();
          return;
        }
        else
        {
          console.log("Inserting " + href + " into DOM");
          //$.mobile.changePage("./" + href, {changeHash: false});
          $.ajax({
            url: href,
            success: function(data) {
              // Finished loading the new page
              data = $(data);
              //console.log("title:",title);
              $(".content-primary").html(data);
              var data = scobeyConverter.fixLinks($(".content-primary"));
              console.log(data);
              var title = $(".content-primary").find('title').text();
              $.mobile.activePage.find("h1").text(title);
              $("#headTitle").text(title);
              // Make sure the menu is collapsed
            }});
          document.location.hash = href;
          
          //$.mobile.loadPage("/m/" + href);
          //setPageUrl = setPage.hash == "" ? setPage.pathname : setPage.hash.replace('#', '');
          //page.attr({'data-url': setPageUrl});
        }
      }
      console.log(href);

    }


  };

})(window.navigator = window.navigator || {});  