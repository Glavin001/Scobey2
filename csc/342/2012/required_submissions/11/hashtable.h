//hashtable.h
//Lastname:Firstname:A00??????:CSC342??
//Submission 11: Implementing a HashTable Class

#include <iostream>
#include <vector>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct FamousPerson
{
    int birthDate;
    string name;
};

namespace Student
{

class HashTable
{
public:
    HashTable();
    /**<
    Default constructor.
    Sets the capacity, size and probe increment to zero.
    */

    bool isEmpty() const;
    /**<
    Returns true or false, according as the hash table
    is empty or non-empty.
    */

    bool isFull() const;
    /**<
    Returns true or false, according as the hash table 
    is full or non-full. Note that "full" can mean a
    capacity of greater than zero and a table that is
    actually full, or a capacity of zero and nothing
    in the table. In a certain sense, this latter table
    is both "empty" and "full".
    */

    void setCapacity
    (
        size_t capacity //in
    );
    /**<
    Sets (or re-sets) the table capacity to the input value.
    */

    void setProbeIncrement
    (
        size_t probeIncrement //in
    );
    /**<
    Sets (or re-sets) the probe increment to the input value.
    */

    size_t getSize() const;
    /**<
    Returns the current size of the hash table (the number of
    data items it contains). This value is <= its capacity.
    */

    size_t getCapacity() const;
    /**<
    Returns the current capacity of the hash table (the number
    of data items it is currently capable of holding). This
    value is >= its size.
    */

    size_t getProbeIncrement() const;
    /**<
    Returns the current value of the probe increment for the
    hashing scheme in use.
    */

    void clear();
    /**<
    Clears the hash table of all data items and resets the 
    capacity, size and probe increment to zero.
    */

    bool isLoaded
    (
        ifstream& inFile, //in
        bool loggingOn    //in
    );
    /**<
    Tries to load the data from inFile into the hash table and returns
    true or false indicating success or failure.
    @return true if the data in the input file inFile has been successfully
    loaded into the hash table, and otherwise false.
    @param inFile The file containing the input data for the hash table.
    @param loggingOn Indicates whether or not the hashLog file should be
    generated.
    @pre inFile is open and contains one or more lines of data in 
    properly formatted form. That is, there is no error checking on
    the format of data in the file.
    @post inFile is still open. As a "side effect", a file called
    "hashLog" has been created. If you were starting from scratch,
    the full description of that file's contents and format would
    be described here. But ... you can obtain an actual hashLog file
    and infer this information from it.
    */

    bool isInserted
    (
        const FamousPerson& dataValue
    );
    /**<
    Tries to insert the person in dataValue into the hash table.
    @return true if the insertion succeeds, and false otherwise.
    @param dataValue The "famous person" to be inserted into the hash table.
    @pre dataValue has been initialized.
    @post Either the person in dataValue has been successfully inserted into
    the hash table, or the hash table remains unchanged.
    */

    bool isRetrieved
    (
        FamousPerson& dataValue //inout
    ) const;
    /**<
    Tries to find a person in the hash table who was born on the birth
    date in the birthDate field of dataValue and return the name of that
    person in the name field of dataValue.
    @return true if the search succeeds, and false otherwise.
    @param dataValue Contains the birth date of the "famous person" being
    sought in the table in its birthDate field, and if the search succeeds,
    will also contain the name of that person in its name field; otherwise
    the name field is undefined.
    @pre dataValue.birthDate has been initialized.
    @post dataValue.name contains the name of the person from the table
    who was born on dataValue.birthDate if such a person exists, and is
    otherwise undefined. In any case, the hash table remains unchanged.
    */

    bool isRemoved
    (
        FamousPerson& dataValue //in
    );
    /**<
    Tries to find the person whose birth date is in dataValue and remove
    that person from the hash table.
    @return true if the removal succeeds, and false otherwise.
    @param dataValue The "famous person" to be removed from the hash table.
    @pre dataValue.birthDate has been initialized.
    @post If a person with birth date dataValue.birthDate has been found in
    the hash table, that person has been removed and that persons name has
    been assigned to dataValue.name. Otherwise dataValue.name is undefined
    and the hash table remains unchanged.
    */

    bool isUpdated
    (
        const FamousPerson& dataValue //in
    );
    /**<
    Tries to find and update the information (which is only the name)
    for the "famous person" in the input dataValue.
    @return true if the person has been found and updated, false otherwise.
    @param dataValue The birthdate and name of the famous person to be
    updated.
    @pre The hash table has been initialized but may or may not contain
    any data.
    @post The information (name) of the person in dataValue has been updated
    (replaced) if the birth date of that person was found in the table.
    Otherwise, the table remains unchanged.
    */

    void displayContentsSequentially() const;
    /**<
    Displays the contents of the hash table in sequential index order,
    with a pause at the end, just so you can see what's in the table at
    any given time.
    */

private:
    vector<FamousPerson> table;
    size_t size;
    size_t probeIncrement;
};

} //End of this part of namespace Student

#endif
