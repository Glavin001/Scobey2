<!--
submit_page.php
Displays form for collection of data
re submission of files for a given week.

Last Updated: Tue Dec  5 22:10:11 AST 2006
Prepared for Jan, 2007
-->

<html>

<head>
<meta http-equiv="Content-Type"
      content="text/html; charset=iso-8859-1">
<title>
CSCI 2342: Making and/or Viewing Submissions
</title>
</head>


<body bgcolor="#FFFFFF"
      text="#800000">
<font face="Verdana, Arial, Helvetica">


<?
if (!preg_match("/^submission=submission[01][0-9]$/", $QUERY_STRING))
{
    echo "<br />Error: Submission string badly formatted!<br />";
    die;
}
?>


<strong>

<?php include("/faculty/porter/htinfo/342/submitdata.php"); ?>
<!--
$submission = submission01, submission02, ...
-->

<p align="center">
<font size="5">
CSCI 2342
Submission  Page
</font>
</p>

<p align="center">
<font color="#FF0000">
<?php echo $submitdata[$submission]['name']; ?><br />
<!--xxxxxphp echo $submitdata[$submission]['week']; xx<br />-->
<?php echo $submitdata[$submission]['desc'] ?><br />
Due Date: <? echo $submitdata[$submission]['due'] ?>
</font>
</p>


<form action="submit.cgi"
      method="POST"
      enctype="multipart/form-data"
      name="Assignment Submission">
      <input type="hidden"
             name="week"
             value="<? echo $submission; ?>">

<!--One-element lists used as kludge for extra spacing-->
<ol start="1">
<li>
    Enter your SMU Student ID Number here:
    <input type="text"
           size="9"
           maxlength="9"
           name="userName"
           value="A00" />
</li>
</ol>

<ol start="2">
<li>
In the table below use the corresponding browse
button at the right to browse your computer and
find the location of each file whose name is
given in the first column of the table.

<p></p>
<table border="1"
       cellpadding="5"
       cellspacing="1"
       width="576">
  <tr>
    <td valign="top"
        width="33%">
      <p align="center">
        <font size="2">
        <strong>
          Name of file to submit
        </strong>
        </font>
      </p>
    </td>
    <td valign="top"
        width="66%">
      <p align="center">
        <font size="2">
        <strong>
          Full pathname to the file (on your computer)
        </strong>
        </font>
      </p>
    </td>
  </tr>

<?php
//
//  Display the files related to this assignment.
//
foreach($submitdata[$submission][files] as $curr_fname) {
echo <<<ENDSTRING
    <tr>
        <td valign="top"
            align="center"
            width="17%">
        <strong>
ENDSTRING
, $curr_fname, <<<ENDSTRING
        </strong>
        </td>
        <td valign="top"
            align="center"
            width="16%">
        <strong>
        <input type="file"
                size="40"
ENDSTRING
, 'name="', $curr_fname,'">', <<<ENDSTRING
        </strong>
        </td>
    </tr>
ENDSTRING;
}
?>

</table>
</li>
</ol>


<ol start="3">
<li>
Select the file in the usual
way by clicking on the filename.
</li>
</ol>


<ol start="4">
<li>
Click the 'Open' button of the browse window,
which should enter into the textbox of column 2
the full pathname to the file whose name appears
in column 1.
</li>
</ol>

<ol start="5">
<li>
    When all information has been
    entered correctly [i.e., when the
    name of the file at the end of the
    full path in column 2 matches the
    name of the corresponding file in
    column 1 (for each file to be
    submitted)], click the button below.
</li>
</ol>

<p align="center">
    <input type="submit"
           name="submit"
           value="Submit All Files">
</p>

</form>

</font>
</strong>
</body>

</html>
