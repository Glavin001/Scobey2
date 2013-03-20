//compute_main_shell.cpp
//Lastname:Firstname:A00123456:csc34101
//Submission 07
//Implementing a Simple Four-Function Calculator

/*
Self-assessment ...
*/

#include whatever standard headers you need here
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

#include "compute_helper_functions.h"

void DisplayUsage();
/**<
Display a brief description of how to use the program.
@pre  None
@post Program usage description has been displayed on standard output.
*/

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        DisplayOpeningScreen("Lastname:Firstname:A00123456:CSC34201",
        "Submission 07: Implementing a Simple Four-Function Calculator");
        DisplayUsage();
        return 1;
    }

    //Pseudocode for your main driver ...
    if (you succeed in reading a valid expression into the expression tree
        and
        there's no garbage on the rest of the line)
        Display the expression, an equals sign, and the expression's value
    else
        Output the message, "Bad input! Could not compute value."
}

void DisplayUsage()
{
    cout << "\nThis program is a simple four-function calculator "
        "with command-line input.\n\nOnly integer arithmetic using "
        "four operators (+, -, *, or /) is permitted.\n\nEach line "
        "of input is limited to either a single positive integer, "
        "or a\nfully-parenthesized arithmetic expression containing "
        "only binary operators\nand positive integer operands.\n\n"
        "Extra spaces in the input are ignored, but any characters "
        "other than blank\nspaces that appear after a valid expression "
        "and on the same line will cause\nthat entire input line to be "
        "rejected as bad input.\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
}
