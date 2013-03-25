/*
 * Author:  Glavin Wiechert
 * Date:    Tuesday, March 19, 2013
 * 
 */

(function(navigator, undefined) {
  // Public Events
  $(document).ready(function() {

    $(document).on('pagebeforechange', function(e, data) {
      console.log('Page before change: ', data.toPage);
      // Go to the Module
      var toPage = (typeof data.toPage === "string") ? data.toPage : data.toPage.jqmData("url") || "";
      navigator.goToPage(toPage);

      // Select this newly loaded page in the nav menu
      $(".content-secondary div ul a").parent().parent().parent().attr('data-theme', 'c').removeClass("ui-btn-up-a").addClass("ui-btn-up-c"); // Select current page
      $(".content-secondary div ul a[href='" + document.location.hash + "']").parent().parent().parent().attr('data-theme', 'a').removeClass("ui-btn-up-c").removeClass("ui-btn-hover-c").addClass("ui-btn-up-a"); // Select current page

      $.mobile.showPageLoadingMsg();

      e.preventDefault();
    });

    // Init 
    scobeyConverter.loadMenu();
    scobeyConverter.init();

  });

  // Public methods 
  navigator.goToPage = function(toPage) {
    console.log("goToPage(" + String(toPage) + ")");
    // Check if the module is already loaded
    //$.mobile.changePage("/m/" + moduleAddress); // , {data:{param1:'value1'}}
    //var url = $.url(document.location);
    //var param1 = url.param("param1"); 
    //document.location.hash = moduleAddress;

    // We only want to handle changePage() calls where the caller is
    // asking us to load a page by URL.
    toPage = decodeURIComponent(toPage);
    var href = "";
    if (typeof(toPage) === "string") {
      href = toPage;
      // location.hash = pageName;

      if (href.search("#") !== -1) {// Check if it is a module
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
          //href = encodeURIComponent(href);

          // Show loading spinner
          $.mobile.showPageLoadingMsg();
          $.ajax({
            url: href,
            success: function(data) {

              console.log("Success");
              // Finished loading the new page
              data = $(data);
              $(".content-primary").html(data);
              var fixedHTML = scobeyConverter.fixLinks($(".content-primary"));
              //console.log("fixed:",fixedHTML.html());
              console.log("fixedLinks");
              $(".content-primary").html(fixedHTML.html());
              var title = $(".content-primary").find('title').text();
              console.log("title:", title);
              $.mobile.activePage.find("h1").text(title);
              $("#headTitle").text(title);
              $('.content-primary .pageheader').replaceWith($('<h1/>').html($('.content-primary .pageheader').html()));

              // Make sure the menu is collapsed
              $('.content-secondary div[data-role="collapsible"]').trigger('collapse');

              // Hide Loading spinner
              $.mobile.hidePageLoadingMsg();
              
            },
            error: function(err) {
              console.log("Ajax error:", err);
              // Hide Loading spinner
              $.mobile.hidePageLoadingMsg();

              // Show error message
              $.mobile.showPageLoadingMsg($.mobile.pageLoadErrorMessageTheme, $.mobile.pageLoadErrorMessage, true);
              // Hide after delay
              setTimeout($.mobile.hidePageLoadingMsg, 1500);

            }
          });
          document.location.hash = ("#" + encodeURIComponent(href));

          //$.mobile.loadPage("/m/" + href);
          //setPageUrl = setPage.hash == "" ? setPage.pathname : setPage.hash.replace('#', '');
          //page.attr({'data-url': setPageUrl});

        }
      }
      console.log(href);
      $(document).scrollTop(0); // Go to top of page after loading new page.
    }
    else
    {
      console.log("Not string:", toPage);
    }
  };

  navigator.scrollToAnchor = function(anchor) {
    var jump = "#" + anchor;
    console.log("Jumping to " + jump);
    var new_position = $(jump).offset();
    window.scrollTo(new_position.left, new_position.top);
    return false;
  };

})(window.navigator = window.navigator || {});  