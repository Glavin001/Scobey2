/* 
 *
 *  Author: Glavin Wiechert
 *  Date: Tuesday, March 19, 2013
 *  Description: Converts the legacy code of Scobey 1.0 to Scobey 2.0
 *  
 */

(function(scobeyConverter, undefined) {
  // private properties
  var home = "#news.html";
  
  // public methods and properties  
  scobeyConverter.menuHTML = "";

  scobeyConverter.init = function() {
    var hash = location.hash || home;
    $.mobile.changePage(hash);
  };

  scobeyConverter.loadMenu = function() {
    $.ajax({
      url: "menu.html",
      success: function(data) {
        scobeyConverter.menuHTML = $(data);
        console.log(scobeyConverter.menuHTML);
        scobeyConverter.menuHTML = tableToList(scobeyConverter.menuHTML);
        scobeyConverter.menuHTML = scobeyConverter.fixLinks(scobeyConverter.menuHTML);
        $(".content-secondary .menu").replaceWith(scobeyConverter.menuHTML);
        $(".menu").listview().listview('refresh');
      }});
  };

  scobeyConverter.fixLinks = function(data) {
    console.log("fixLinks",typeof(data));
    var html = $(data); //(typeof(data) === "object")?(data):$(data);
    scobeyConverter.menuHTML = html;
    console.log("Started:",html);
    $.each(html.find("a"), function() {
      //console.log(this);
      var target = $(this).attr('target');
      var href = $(this).attr('href');
      if (target && target === "display_frame") // Originally sent to frame
      {
        $(this).attr('href', "#" + href);
        $(this).attr('target', "");
      }
      else if (href && href.indexOf("#") === 0) // Originally an in-page anchor
      {
        $(this).attr('href', "javascript:void(0);");
        $(this).attr('target', "");
        
        $(this).click(function() {
          var jump = href;
          var new_position = $(jump).offset();
          window.scrollTo(new_position.left, new_position.top);
          return false;
        });
        
      }
      else
      {
        $(this).attr('href', href);
        $(this).attr('target', "_blank");
      }
    });
    console.log("Finished:",html);
    return html;
  };

  // private method  
  function tableToList(tableData) {
    console.log("tableToList", tableData);
    /*
     <li data-role="list-divider">Overview</li>
     <li data-theme="a"><a href="../../docs/about/intro.html">Intro to jQuery Mobile</a></li>
     <li><a href="../../docs/about/getting-started.html">Quick start guide</a></li>	
     */
    var newHTML = $("<ul />", {'class': "menu ui-listview", 'data-role': "listview", 'data-theme': "c", 'data-dividertheme': "d"});
    $.each($(tableData).find("tr td"), function(index, value) {
      //console.log(index, $(value) );

      var el = $("<li />");
      // Deal with Font elements
      if ($(value).find("font").length > 0)
      {
        // It's a font element
        el.attr('data-role', 'list-divider');
        el.text($($(value).find("font")[0]).text());
        //el.html(contents);
      }
      // Deal with anchor elements
      if ($(value).find("a").length > 0)
      {
        // It's a font element
        //el.attr('data-role', 'list-divider');
        var a = $("<a />");
        // a.attr('class', $($(value).find("a")[0]).attr('class'));
        /*
         var target = $($(value).find("a")[0]).attr('target');
         if (target == "display_frame")
         {
         a.attr('href', "#" + $($(value).find("a")[0]).attr('href'));
         }
         else
         {
         a.attr('href', $($(value).find("a")[0]).attr('href'));
         a.attr('target', "_blank");
         }
         */
        a.attr('href', $($(value).find("a")[0]).attr('href'));
        a.attr('target', $($(value).find("a")[0]).attr('target'));

        a.text($($(value).find("a")[0]).text());
        el.append(a);
      }
      // Add element to newHTML
      //console.log(el);
      $(newHTML).append(el);
    });
    return newHTML;
  }
  ;

  // check to evaluate whether 'namespace' exists in the  
  // global namespace - if not, assign window.namespace an  
  // object literal  
})(window.scobeyConverter = window.scobeyConverter || {});
