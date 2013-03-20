//club_members_shell.cpp
//Lastname:Firstname:A00123456:csc34201
//Submission 06: Using a Binary File to Process Club Member Data

/*
Self-assessment goes here ...
*/

//Put whatever standard headers you need here
using namespace std;

#include "utilities.h"
//Put your using declarations for the utilities package here

#include "club_members.h"

//Modify the following line to contain your information
extern const string MY_ID_INFO = "Lastname:Firstname:A00123456:csc34201";

void BuildMenu
(
    Menu& menu //inout
)
{
    menu.setTitle("Menu");
    menu.addOption("Quit");
    menu.addOption("Get information");
    menu.addOption("Read a textfile of club member data into a "
        "working binary file");
    menu.addOption("Display all club member data from the binary file");
    menu.addOption("Display data for one or more club members from the "
        "binary file");
    menu.addOption("Add a new club member to the working binary file");
    menu.addOption("Update a club member's data in the binary file");
    menu.addOption("Write the working binary file of club member data "
        "to a textfile");
    menu.addOption("Display any textfile");
}


//Put here the rest of the function definitions/implementations)
//of the functions you have to write, in the same order as you
//find their prototypes in the .h file.


void DisplayAnyTextfile()
{
    string fileName;
    ReadString("Enter name of file to display: ", fileName);
    DisplayTextfile(fileName);
}
