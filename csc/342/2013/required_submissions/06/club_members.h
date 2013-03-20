//club_members.h
//Lastname:Firstname:A00123456:csc34201
//Submission 06: Using a Binary File to Process Club Member Data


/**
The struct used to contain the information for a club member.
The binary working file must be a binary file of this type.
*/
struct ClubMember
{
	char name[31];
	int age;
	double balance;
};


void BuildMenu
    (
    Menu& menu //inout
    );
/**<
Gives the input menu the required title and options.
@param menu The menu to be given a title and options.
@pre menu has been initialized.
@post menu contains the appropriate title and options.
*/


void TransferTextToBinary
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Transfers a textfile of club member data to a "working" binary file
of same.

If there is a problem opening either the textfile or the binary file,
one or the other of the following messages is displayed, followed by
a pause:
<pre>
Error opening input textfile.
Returning to menu.

Error opening working binary file.
Returning to menu.
</pre>

The prompt for the name of the textfile looks like this:
<pre>
Enter name of input textfile containing club members:
</pre>
The data for each club member in the textfile consists of the member's
name, age, and account balance, appears on two lines, and looks like
this (with a single space between the age and the $):
<pre>
John Smith
19 $47.53
</pre>
The program reads the information in and writes it out to the binary
file ioFile. Finally, the textfile is closed, but the binary file
remains open.
@param ioFile The binary file of club members.
@param successful true if the data has been successfully transferred
from the textfile to the working binary file; false otherwise.
@pre A textfile of properly formatted club member data is available.
@post The textfile of club member data has been transferred to a working
binary file, ioFile, which is open for reading and writing, and successful
is true; or, an error opening either the input textfile or the output
binary file has been reported, ioFile is not open, and successful is false.
*/


void DisplayAllMembers
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Displays the data for all club members in the working binary file, eight
at a time.

If ioFile is not yet open for reading, the following message is displayed,
followed by a pause:
<pre>
Binary file not yet open.
Returning to menu.
</pre>

The display for each member occupies three lines and looks like this:
<pre>
====================
John Smith
Age: 19  Balance: $47.53
</pre>
Note that there are two spaces between the age number and the word
"Balance". Also, there is a pause after the display of each 8 members.
@param ioFile The binary file of club members.
@param successful true if all club member data has been displayed; false
if the file ioFile is not yet open and ready for reading.
@pre The working binary file ioFile is available.
@post All club member data in ioFile has been displayed and successful is
true; or, ioFile is not yet open for reading, an error has been reported,
and successful is false.
*/


void DisplayOneOrMoreMembers
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Displays the data for all club members whose names contain a search
string entered by the user.

If ioFile is not yet open for reading, the following message is displayed,
followed by a pause:
<pre>
Binary file not yet open.
Returning to menu.
</pre>

The prompt for a search string looks like
this:
<pre>
Enter full or partial name of member(s) whose data you wish to display:
</pre>
The display for each member occupies three lines and looks like this:
<pre>
====================
John Smith
Age: 19  Balance: $47.53
</pre>
Note that there are two spaces between the age number and the word
"Balance". In this case there is no pause after the display of each
8 members since it is unlikely that 8 or more members will be displayed.
@param ioFile The binary file of club members.
@param successful true if all club member data has been displayed; false
if the file ioFile is not yet open and ready for reading.
@pre The working binary file ioFile is available.
@post The data for all club members (if any) in ioFile whose names contain
the search string entered by the user has been displayed and successful is
true; or, ioFile is not yet open for reading, an error has been reported,
and successful is false.
*/


void AddNewMember
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Adds a new club member to the end of the "working" binary file.

If ioFile is not yet open for writing, the following message is displayed,
followed by a pause:
<pre>
Binary file not yet open.
Returning to menu.
</pre>

Asks for the new member's data with the following prompts:
<pre>
Enter name of new member:
Enter age of new member:
Enter opening balance of new member:
</pre>
Then writes the information to the end of the binary working file.

@param ioFile The binary file of club members.
@param successful true if the new club member data has been displayed;
false if the file ioFile is not yet open and ready for reading.
@pre The working binary file ioFile is available.
@post The data for the new club member has been added to the end of the
working binary file and successful is true; or, ioFile is not yet open
for writing, an error has been reported, and successful is false.
*/


void UpdateMemberData
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Updates any part of the data for a single club member.

If ioFile is not yet open for writing, the following message is displayed,
followed by a pause:
<pre>
Binary file not yet open.
Returning to menu.
</pre>

The member whose data is
to be updated must be the (unique) club member whose name contains the
search string entered by the user in response to the following prompt:
<pre>
Enter enough of the member's name to identify him/her:
</pre>
All club members who satisfy the search string are displayed, like this:
<pre>
====================
John Smith
Age: 19  Balance: $47.53
</pre>
If no members, or more than one member, are displayed in response to the
entered search string, the following message is displayed, following which
the function returns:
<pre>
=====>Either more than one member, or no members, matched your input.
=====>You need to identify a unique club member to update.
=====>Try again with more specific input.
</pre>
If a single member is displayed in response to the entered search string,
the message
<pre>
Updating data for the above club member.
</pre>
is output and the user is then (repeatedly) prompted for any changes to
be made to that user's data with these prompts, displayed as appropriate:
<pre>
Enter n/a/b to update name/age/balance, or q to quit updating this member:
Enter revised name:
Enter revised age:
Enter revised balance:
</pre>
When the user decides no further updates are required, the following
message is displayed:
<pre>
OK, no more updates for this club member at this time.
</pre>
The user may enter a lower or upper case n, a, b, or q to indicate the
requested action, but if something else is entered, the message
<pre>
Error: Invalid entry.
Please try again.
</pre>
is displayed, after which the user is given another opportunity to enter
a choice.
@param ioFile The binary file of club members.
@param successful true if a club member's data has been updated; false
if the file ioFile is not yet open and ready for reading.
@pre The working binary file ioFile is available.
@post The data for a club member has been updated and successful is true;
or, ioFile is not yet open for writing, an error has been reported, and
successful is false.
*/


void WriteTextArchiveAndDeleteBinary
    (
    fstream& ioFile, //inout
    bool& successful //out
    );
/**<
Transfers all club member data from the working binary file to an output
textfile for "archiving", and potential future use as an input textfile.

If there is a problem opening the textfile for output or if the binary
file is not yet open, the appropriate choice of message from the following
two messages is displayed, followed by a pause:
<pre>
Error opening out textfile.
Returning to menu.

Binary file not yet open.
Returning to menu.
</pre>

The prompt for the name of the textfile looks like this:
<pre>
Enter name of output textfile for archiving club member data:
</pre>
The data for each club member in the output textfile consists of the
member's name, age, and account balance, appears on two lines, and
looks like this (with a single space between the age and the $, as
in the original input file):
<pre>
John Smith
19 $47.53
</pre>
Both the output textfile and the binary working file are closed,
and the binary working file is then deleted.
@param ioFile The binary file of club members.
@param successful true if the data for a club member has been
successfully updated in the working binary file; false otherwise.
@pre A binary working file is available.
@post One club member's data in the working binary file has been
updated; or, an error has been reported, ioFile is not open, and
successful is false.
*/


void DisplayAnyTextfile();
/**<
Prompts the user for the name of a textfile and displays that file
one screen at a time. Displays an error if the file cannot be opened.
@pre A textfile is available for display.
@post The textfile has been displayed, a screen at a time, with
appropriate messages; or, an error message has been displayed if
the file to be displayed cannot be opened.
*/
