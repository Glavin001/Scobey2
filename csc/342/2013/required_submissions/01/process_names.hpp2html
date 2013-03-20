//process_names.hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib> //for access to srand()
#include <iterator>
using namespace std;

#include "utilities.h"
using Scobey::NAMES_FEMALE;
using Scobey::NAMES_MALE;
using Scobey::NAMES_FAMILY;
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::Menu;

const string MY_ID_INFO = "Lastname:Firstname:A00123456:csc34201";
const string SUBMISSION_ID_INFO = "Submission 01: Processing Names";
const int NUMBER_OF_NAMES = 24;

void DisplayProgramInfo()
{
    cout << "\nThis is a menu driven program which allows the user "
        "to genenerate exactly 24\nrandom names, and subsequently "
        "display the names in several ways."

        "\n\nThe number 24 has been chosen simply because that number "
        "of names displayed one\nper line fills the screen but leaves "
        "one line for a pause at the bottom."
        
        "\n\nEach name consists of a first name followed by a last "
        "name (that is, a family\nname), with a single space between "
        "the two. Neither the first name nor the last\nname will itself "
        "contain any spaces. Each name is formed by choosing a random"
        "\nfirst name from the 300 most popular female first names or "
        "from the 300 most\npopular male first names in the USA, and this "
        "is then combined with a randomly\nchosen last name from the 100 "
        "most frequently observed family names in the USA."
        
        "\n\nOnce the names have been generated, they may be displayed "
        "in any of the\nfollowing ways:"

        "\n\n-- Exactly as generated, and in the same order"
        "\n-- As generated, but with first names in alphabetical order"
        "\n-- As generated, but with last names in alphabetical order"
        "\n-- With last names first, in alphabetical order, and "
        "with each last name\n   separated from its corresponding "
        "first name by a comma and a blank space\n\n\n";
}


void AddOptionsToMenu
(
    Menu& menu //inout
)
{
    menu.addOption("Quit");
    menu.addOption("Get information");
    menu.addOption("Generate names");
    menu.addOption("Display names as generated");
    menu.addOption("Display names with first names in alphabetical order");
    menu.addOption("Display names with last names in alphabetical order");
    menu.addOption("Display names with last names first, "
        "in alphabetical order");
}
