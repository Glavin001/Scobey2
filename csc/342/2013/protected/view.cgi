#!/usr/bin/perl

# view.cgi
# From /faculty/porter/public_html/csc/342/2013/protected
# Shows the student the file(s) submitted
# for a particular submission.
#
# Change Log: Fri Dec 17 13:03:10 AST 2004
# Added error checking on input query string.
# Changed "week" to "submission" to reflect direcory name changes.

# Last Updated: Tue Jun 12 17:49:14 ADT 2012
# Prepared for Jan, 2013


########################## Begin Main Program #######################
use CGI;
$submit = new CGI;
$submission    = $submit->param(submission);
print $submit->header;

$userName = $ENV{REMOTE_USER};
$qString  = $ENV{QUERY_STRING};
$submissionNumber = substr($qString, 21, 2);
$testString = substr($qString, 0, 21);
if ((length($qString) != 23) or
    ($testString ne "submission=submission") or
    !($submissionNumber >= 1  and  $submissionNumber <= 13))
{
   print ("<font color=\"red\"><p><big>Error: Bad submission string </big></p></font>\n");
   die;
}

require("/faculty/porter/htinfo/342/idlist.pl");
$account = $classacct{"$userName"};

&DisplayInformation;
########################### End Main Program ########################

# Display information on one week's submitted files to the user
sub DisplayInformation()
{
    print "<pre>";

    print ("+++++++++++++++++++++++++++++++++++++",
           "+++++++++++++++++++++++++++++++++++++");
    print "\nA list of your submitted files ",
          "for $submission is shown below.";
    print "\nBe sure to check the name(s) and ",
          "byte-size(s) carefully.\n\n";
    print "Name of file submitted      Size in bytes\n";
    print "----------------------      -------------\n";

    $base = "/faculty/porter/htinfo/342/submissions/2013";
    $listing1 =
    `ls -l $base/$account/$submission | \
    awk '{ if (\$9) {\
               len = length(\$9);\
               dots = ".";\
               for (i = 1; i <= 25-len; i=i+1) dots = dots ".";\
               print \$9 " " dots " " \$5\
           }\
         }'`;

    print $listing1;
    print "\n";

    #if (open(PROFILE, "</faculty/porter/htinfo/342/profiles/$userName"))
    if (open(PROFILE, "</faculty/porter/htinfo/342/profiles/$account"))
    {
        # Read first three lines of student profile
        # and display lines 2 and 3.
        $line = <PROFILE>;
        $line = <PROFILE>; print $line;
        $line = <PROFILE>; print $line;
        close PROFILE;
    }
    else
    {
        print "\nError: Could not open database profile for $userName\n";
    }

    print ("+++++++++++++++++++++++++++++++++++++",
           "+++++++++++++++++++++++++++++++++++++");
    print "\nDate and time this page was displayed: ", `date`;
    print "</pre>";
}
