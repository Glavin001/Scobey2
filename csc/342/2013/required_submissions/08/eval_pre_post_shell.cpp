//eval_pre_post_shell.cpp
//Lastname:Firstname:A00123456:CSC34201
//Submission 08: Evaluating Prefix and Postfix Expressions

//Include whatever header files you need here
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

//If you want any global constants, put them here.

//If you want to use the (suggested) Exception class, put it here.

void DisplayUsage();
/**<
Displays a brief program usage description on the standard output.
@pre None
@post A program usage description has been displayed, with a pause
at the end for the user to press Enter to continue.
*/

//Put the prototypes for whatever other functions you use here,
//complete with doxygen-style documentation.

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        Scobey::DisplayOpeningScreen("Lastname:Firstname:A00123456:CSC34201",
            "Submission 08: Evaluating Prefix and Postfix Expressions");
        DisplayUsage();
        return 1;
    }

    //Put the rest of your main() driver code here.
}


void DisplayUsage()
{
    cout <<"This program evaluates any valid prefix or postfix "
        "expression which\ncontains positive integer operands and the "
        "operators +, -, * and/or /.\nThe expression to be evaluated "
        "must be entered on the command line.\nA single positive integer "
        "also evaluates as itself."

        "\n\nTypical usage examples:"
        "\n> eval_pre_post + * 2 3 4"
        "\n+ * 2 3 4 = 10"
        "\n> eval_pre_post 2 3 4 + *"
        "\n2 3 4 + * = 14"
        
        "\n\nThe following errors are recognized and reported:"
        "\n\nFor prefix expressions:"
        "\nError: End of prefix expression reached unexpectedly."
        "\nError: Bad operator ? encountered evaluating prefix expression."
        "\nError: Extraneous characters found after valid prefix expression."
        "\n\nFor postfix expressions:"
        "\nError: End of postfix expression reached unexpectedly."
        "\nError: Bad operator ? encountered evaluating postfix expression."
        "\nError: Not enough operands for postfix operator ?."
        "\nError: Found too many operands when evaluating postfix expression."
        "\n";
    Pause();
}


//Put your function definitions here, in the same order as your function
//prototypes above.