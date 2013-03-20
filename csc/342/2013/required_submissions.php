<?
//required_submissions.php
//Submits files and/or shows those already submitted.
?>

<html>

<head>
<meta http-equiv="Content-Type"
      content="text/html; charset=iso-8859-1">
<title>
CSC 2342: Required Submissions
</title>
<link rel="StyleSheet"
      href="/~porter/css/courses.css"
      type="text/css"
/>
</head>



<body class="csc342">

<?
if ($QUERY_STRING != "")
{
    echo "<br />Error: No link parameters permitted!<br />";
    die;
}
?>

<p class="pageheader">
Required Submissions for CSCI 2342
</p>

<p class="intro">
This is the index page showing all on-line
submissions you must "hand in" (electronically)
during the term. Each submission will be graded,
and you will be provided with appropriate feedback.
Be sure to read the web page describing the course
grading scheme for additional relevant information
regarding this part of the course work.
</p>



<table border="2"
       cellpadding="4"
       cellspacing="1"
       bordercolor="#00FF00"
       bordercolordark="#008000"
       bordercolorlight="#008000">

<tr>
<!--<th>Week</th>-->
<th>Submission #</th>
<th>Due Date</th>
<th>Points</th>
<th colspan="2">
Action (<font color="red">protected links</font>)
</th>
</tr>

<!--First column of table, corresponding to "Week" above
<td align="center">
STRING
, substr($key, 10, 11), <<<STRING
</td>
-->

<?php
include("/faculty/porter/htinfo/342/submitdata.php");
foreach($submitdata as $key => $value)
{
echo <<<STRING
<tr>
<td>
  <a href="required_submissions/
STRING
, $key, <<<STRING
.html">
  <strong>
STRING
, $value[name], <<<STRING
</strong></a>
</td>
<td>
  <strong>
STRING
, $value[due], <<<STRING
</strong>
</td>
<td align="center">
  30
</td>
<td>
  <a href="protected/submit_page.php?submission=
STRING
, $key, <<<STRING
">
  <strong>Submit</strong></a>
</td>
<td>
  <a href="protected/view.cgi?submission=
STRING
, $key, <<<STRING
">
  <strong>View Submission</strong></a>
</td>
</tr>
STRING;
}
?>

</table>

</body>
</html>
