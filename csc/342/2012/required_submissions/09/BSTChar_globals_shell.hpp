//BSTChar_globals?.hpp
//Lastname:Firstname:A00123456:CSC34201
//Submission ??: Implementing an ADT Binary Search Tree of Characters, Part ?
//Contains several "high-level" utility functions used by main to handle user
//interaction for creating and manipulating a binary search tree of characters.

#include "utilities.h"
using Scobey::Menu;
using Scobey::Pause;
using Scobey::userSaysYes;

void BuildMenu
(
    Menu& m //inout
)
/**<
@pre None
@post The main menu for the BST test driver, Part 1,
has been constructed.
*/
{
    m.setTitle("Menu");
    m.addOption("Quit");
    m.addOption("Get info");
    m.addOption("Enter characters from keyboard and place them into a BST");
    m.addOption("Display contents of the BST");
    m.addOption("Report the size of the BST");
    m.addOption("Report the height of the BST");
    m.addOption("Clear the BST of all values");
    m.addOption("Search the BST for a particular value");
    m.addOption("Insert a new value into the BST");
    m.addOption("Delete a single value from the BST");
    m.addOption("Modify all values in the BST");
    m.addOption("Balance the BST");
}


void DescribeProgram()
/**<
@pre None
@post A description of each menu option has been displayed.
*/
{
    cout << "\nThis program performs some tests on binary search trees. "
        "The user can choose\nvarious options from the menu, in any order."

        "\n\nOptions 1 and 2 provide the usual program termination and "
        "information display."

        "\n\nOption 3 builds a binary search tree containing characters "
        "entered by the user\nfrom the keyboard."

        "\n\nOption 4 displays the contents of the current binary search "
        "tree in a tree-like\nshape that depends on the size of the tree. "
        "A tree with a depth greater than 4\ncannot be displayed."

        "\n\nOption 5 gets the size of the current binary search tree."

        "\n\nOption 6 gets the height of the current binary search tree."

        "\n\nOption 7 deletes all vlaues from the current binary seach tree."

        "\n\nOption 8 allows the user to determine if a particular value "
            "is in the BST."

        "\n\nOption 9 allows the user to enter a new value into the BST."

        "\n\n";

        Pause();

        cout << "Option 10 allows the user to delete a value from the BST."

        "\n\nOption 11 allows the user to modify all values in the BST."

        "\n\nOption 12 balances the BST."
        "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}


void BuildTree
(
    BSTChar& bst //inout
);
/**<
Build a new binary search tree from characters entered by the user from
the keyboard.
@return void
@param bst The tree object which will contain the entered characters.
@pre bst has been initialized.
@post bst contains all characters entered by the user and is a binary
search tree.
*/



void DisplayTree
(
    BSTChar& bst //in
);
/**<
Display the contents of a binary search tree, or a message saying the
tree is empty or too large to display, if that is the case.
@return void
@param bst The binary search tree whose contents are to be displayed.
@pre bst has been initialized.
@post The contents of bst, or an appropriate message, have been displayed.
*/



void GetTreeSize
(
    const BSTChar& bst //in
);
/**<
Display the size of a binary search tree, or a message saying the tree
is empty if that is the case.
@return void
@param bst The binary seach tree whose size is desired.
@pre bst has been initilaized.
@post The size of bst, or an empty-tree message, has been displayed.
*/


void GetTreeHeight
(
    const BSTChar& bst //in
);
/**<
Display the height of a binary search tree, or a message saying the tree
is empty if that is the case.
@return void
@param bst The binary seach tree whose height is desired.
@pre bst has been initilaized.
@post The height of bst, or an empty-tree message, has been displayed.
*/


void DeleteAllValues
(
    BSTChar& bst //inout
);
/**<
Clear a binary search tree by deleting all of its values, or report that the
tree is already empty, if that is the case.
@return void
@param bst The binary search tree to be cleared.
@pre bst has been initialized.
@post bst has been cleared, or a message has been displayed saying it was
already empty.
*/


void FindAValue
(
    const BSTChar& bst //in
);
/**<
Determine whether a value entered by the user is present in the current
binary search tree.
@return void
@param bst The binary search tree to be cleared.
@pre bst has been initialized.
@pre A message indicating whether the tree is empty, or, if not, whether
the value entered by the user is in fact in the current binary search tree.
*/


void InsertAValue
(
    BSTChar& bst //inout
);
/**<
Insert a new value into the current BST if it is not already there.
@return void
@param bst The binary search tree into which the value will be inserted.
@pre bst has been initialized.
@post A value entered by the user has been inserted into the BST, or a
message indicating the value is already there has been displayed.
*/


void DeleteAValue
(
    BSTChar& bst //inout
);
/**<
Delete a value from the current BST if it is present.
@return void
@param bst The binary search tree from which the value will be deleted.
@pre bst has been initialized.
@post A value entered by the user has been deleted from the BST, or a
message indicating the value is not present has been displayed.
*/

//Two simple functions used to modify all values in a BST
//-------------------------------------------------------
//Shift a character value one position to the left
void ShiftLeftByOne(char& c);
//Shift a character value one position to the right
void ShiftRightByOne(char& c);


void ModifyAllValues
(
    BSTChar& bst //inout
);
/**<
Modify all values in the BST according to the choice entered by the user.
@return void
@param bst The binary search tree whose values are to be modified.
@pre bst has been initialized.
@post All values in the BST have been modified according to the modification
choice entered by the user, or an empty-tree message has been displayed.
*/


void BalanceTree
(
    BSTChar& bst //in
);
/**<
Balance the binary search tree so that for each node of the tree, the
height of the left subtree and the height of the right subtree differ
by zero or one.
@return void
@param bst The binary search tree to be balanced.
@pre bst has been initialized.
@post The binary search tree has been balanced, or an empty-tree message
has been displayed.
*/
