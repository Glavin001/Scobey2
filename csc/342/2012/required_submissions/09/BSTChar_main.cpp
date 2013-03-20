//BSTChar_main?.cpp
//Lastname:Firstname:A00123456:CSC34201
//Submission ??: Implementing an ADT Binary Search Tree of Characters, Part ?

/*
Self-assessment and description of implemented parts ...
*/

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Menu;
using Scobey::Pause;

#include "BSTChar_class.h"
#include "BSTChar_globals.hpp"

int main()
{
    DisplayOpeningScreen("Lastname:Firstname:A00123456:CSC34201",
        "Submission ??: "
        "Implementing an ADT Binary Search Tree of Characters, Part ?");

    BSTChar bst;

    Menu menu;
    BuildMenu(menu);
    int menuChoice;
    do
    {
        menu.display();
        menuChoice = menu.getChoice();
        switch(menuChoice)
        {
        case -1:
        case 1:  cout << "Program now terminating.\n"; break;
        case 2:  DescribeProgram();    break;
        case 3:  BuildTree(bst);       break;
        case 4:  DisplayTree(bst);     break;
        case 5:  GetTreeSize(bst);     break;
        case 6:  GetTreeHeight(bst);   break;
        case 7:  DeleteAllValues(bst); break;
        case 8:  FindAValue(bst);      break;
        case 9:  InsertAValue(bst);    break;
        case 10: DeleteAValue(bst);    break;
        case 11: ModifyAllValues(bst); break;
        case 12: BalanceTree(bst);     break;
        }
        Pause();
    }
    while (menuChoice != -1  &&  menuChoice != 1);
}
