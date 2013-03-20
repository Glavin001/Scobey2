#!/usr/bin/perl

# submit.cgi
# From /faculty/porter/public_html/csc/342/2013/protected
# Submits the file(s) required for a particular submission.

# Last Updated: Tue Jun 12 17:47:15 ADT 2012
# Prepared for Jan, 2013

use CGI;

########################## Begin Main Program #######################
$submit = new CGI;
print $submit->header;
print "\n";

$userName = $ENV{REMOTE_USER};
$week     = $submit->param(week);
require("/faculty/porter/htinfo/342/idlist.pl");
$account = $classacct{"$userName"};

$qString = $ENV{QUERY_STRING};
if (length($qString) != 0)
{
   print ("<font color=\"red\"><p><big>Error: Non-zero-length query string</big></p></font>\n");
   die;
}

&CheckUsername;
&CopyFiles;
&DisplayInformation;
&UpdateLogAtEnd;
########################### End Main Program ########################


#################### Check if the username matches ##################
sub CheckUsername()
{
    print "<pre>";
    if($userName ne $submit->param(userName))
    {
        print "Your username does not match the one used for login.";
        die;
    }
    if (!(-e "/faculty/porter/htinfo/342/profiles/$account"))
    {
        print "You have not signed up for the web site.";
        die;
    }
    print "</pre>";
}


######################## Copy all the files ############################
sub CopyFiles()
{
    print "<pre>";
    foreach $filename ($submit->param())
    {
        if ($filename ne "userName" &&
            $filename ne "submit"   &&
            $filename ne "account"  &&
            $filename ne "week" )
        {
            $file = $submit->param($filename);

            $base = "/faculty/porter/htinfo/342/submissions/2013";
            if (!open(OUTFILE, ">$base/$account/$week/$filename"))
            {
                print "Could not open the file ";
                print "$account/$week/$filename for $userName\n";
                die;
            }

            print "\nWriting file $account/$week/$filename.";
            while ($bytesread = sysread($file, $buffer, 1024))
            {
                print OUTFILE $buffer;
            }
            close OUTFILE;

            if (-z "$base/$account/$week/$filename")
            {
                print "File $account/$week/$filename is empty.";
            }
        }
    }
    print "</pre>";
}


# Display information to the user
sub DisplayInformation()
{
    print "<pre>";
    print "++++++++++++++++++++++++++++++++++",
          "++++++++++++++++++++++++++++++++++";
    print "\nThe files named above have ";
    print "been successfully submitted for you.";
    $date = `date`;
    print "\nPrint this page as proof of submission on this date: $date";
    print "\nAs a further check, compare the name and size of each ";
    print "\nfile shown below with the files you submitted.\n";
    $base = "/faculty/porter/htinfo/342/submissions/2013";
    $listing = `ls -l $base/$account/$week|awk '{print \$9,"\t",\$5}'`;
    print $listing;

    if(open(PROFILE, "</faculty/porter/htinfo/342/profiles/$account"))
    {
        $line = <PROFILE>; print $line;
        $line = <PROFILE>; print $line;
        $line = <PROFILE>; print $line;
        $line = <PROFILE>; print $line;
    }
    else
    {
        print "Could not open database profile for $userName";
    }
    print "++++++++++++++++++++++++++++++++++",
          "++++++++++++++++++++++++++++++++++";
    print "</pre>";
}


# Update the student's log file
sub UpdateLogAtEnd()
{
    # Store personal information
    if(open (OUTFILE, ">>/faculty/porter/htinfo/342/logs/$account"))
    {
        $date = `date`;
        chomp($date);
        print OUTFILE "\n$week files submitted by $userName on $date.";
        close OUTFILE;
    }
    else
    {
        print "Could not open log file for $userName\n";
        die;
    }
    chmod (0770, "/faculty/porter/htinfo/342/logs/$account");
}

