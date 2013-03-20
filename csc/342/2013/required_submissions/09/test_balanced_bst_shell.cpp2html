//test_balanced_bst_shell.cpp
//Lastname:Firstname:A00123456:CSC34201
//Submission 09: Creating and Displaying Balanced Binary Search Trees

//Your #include headers from the standard library go here
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::Menu;
//using whatever else you want to use from the utilities package

struct TreeNode
{
    TreeNode* leftPtr;
    char      data;
    TreeNode* rightPtr;
};

void AddMenuOptions
(
    Menu& m //inout
);
/**<
Builds the required menu by adding the necessary options.
*/

//Other function prototypes, with doxygen documentation

int main()
{
    DisplayOpeningScreen("Lastname:Firstname:A00123456:CSC34201",
        "Creating and Displaying Balanced Binary Search Trees");

    //Other declarations ...
    Menu m("Menu for Balanced Character BST Creation and Display");
    AddMenuOptions(m);
    int menuChoice;
    do
    {
        m.display();
        menuChoice = m.getChoice();
        switch (menuChoice)
        {
        case 1: case -1:
            break;
        case 2:
            //Code to read character values into the vector
            Pause(0, "All characters have been entered into the vector.");
            break;
        case 3:
            //Code to generate the vector of random character values
            Pause(0, "All values have been generated.");
            break;
        case 4:
        	//Code to display the characters in the vector
            cout << "\nHere are the current contents of the vector:\n" << endl;
            Pause(0, "\n");
            break;
        case 5:
        	//Code to create the balanced binary search tree
            Pause(0, "The balanced binary search tree has been created.");
            break;
        case 6:
            //if (tree is empty)
            //    cout << "Tree is empty. Nothing to display.\n";
            //else if (tree height <= 3)
            //    Display the tree
            //else
            //    cout << "\nHeight of tree is too great for display (>=4).\n";
            Pause();
            break;
        }
    }
    while (menuChoice != 1 && menuChoice != -1);
    Pause(0, "Program now terminating.");
}

void AddMenuOptions
(
    Menu& m //inout
)
{
    m.addOption("Quit");
    m.addOption("Enter a vector of <= 15 unique values from the keyboard");
    m.addOption("Generate a vector of <= 15 unique random values");
    m.addOption("Display the vector of values");
    m.addOption("Put the vector of values into a balanced BST");
    m.addOption("Display the tree if its height is <= 3 (which it should be)");
}

//Other function definitions in the same order as your prototypes above ...