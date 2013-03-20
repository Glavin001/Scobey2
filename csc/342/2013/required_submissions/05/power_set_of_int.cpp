//power_set_of_int.cpp
//Firstname:Lastname:A00123456:csc34201
//Submission 05: Building and Displaying Power Sets

#include <iostream>
#include <set>
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::ReadInt;
using Scobey::Pause;

template <typename T>
set<set<T>> powerSet
    (
    const set<T>& sOriginal //in
    );
/**<
Compute and return the power set of sOriginal.
@return The power set of the input set.
@param SOriginal The set of values whose power set is to be computed.
@pre sOriginal has been initialized.
@post The power set of sOriginal has been returned.
*/

template <typename T>
void WritePowerSet
    (
    const set<set<T>>& pSet //in
    );
/**<
Output the elements of the power set pSet, four per line.
Each set of the power set is displayed as a comma-separated
list of elements enclosed within braces. The sets themselves
on any line are separated by two blank spaces.
*/

int main()
{
    DisplayOpeningScreen("Firstname:Lastname:A00123456:csc34201",
        "Submission 05: Building and Displaying Power Sets");
    cout << "\nThis program prompts for an integer value n and builds "
        "the set\n{1, 2, 3, ..., n}. It then calls a (recursive) function "
        "powerSet()\nthat returns the power set of the set. The power set "
        "is the set of\nall subsets of the set and has 2^n elements. "
        "After displaying the\nsize of the power set, the program calls "
        "the function WriteAllSubsets()\nthat outputs each subset using "
        "the notation {e_1, e_2, ..., e_m},\nfour sets per line.\n\n";
    Pause();

    int n;
    ReadInt("Enter a non-negative integer "
    	"(<= 6 if you don't want a lot of output): ", n);

    set<int> sInt; //Set of integers whose power set we construct
    for (int i=1; i<=n; i++) sInt.insert(i); //Build set {1,2,3, ..., n}

    set<set<int>> pSet = powerSet(sInt); //Build the power set

    //Output number of subsets, followed by all subsets, four per line
    cout << "\nNumber of subsets = " << pSet.size()
        << ", and here they are:\n";
    WritePowerSet(pSet);
    Pause();
}

#include "power_set_funs.hpp"
