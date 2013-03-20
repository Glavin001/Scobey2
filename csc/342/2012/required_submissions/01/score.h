//score.h

#ifndef SCORE_H
#define SCORE_H

#include <string>
using namespace std;

/**
A class of 2-digit scores for 4-digit codes, for use in a guessing game
that pits the computer as codebreaker against the user as codemaker.
*/
class Score
{
friend istream& operator>>
    (
    istream& inputStream, //inout
    Score& score          //out
    );
    /**<
    Reads a Score object from the input stream.
    @return A reference to the <tt>inputStream</tt> object.
    @param inputStream The stream from which the Score object is to be read.
    @param score The receiving variable for the Score object.
    @pre inputStream is open and ready for reading.
    @post An object of type Score has been read in and <tt>inputStream</tt>
    is still open.
    */

friend ostream& operator<<
    (
    ostream& outputStream, //inout
    const Score& score     //in
    );
    /**<
    Writes a Score object to an output stream.
    @return A reference to the <tt>outputStream</tt> object.
    @param outputStream The stream to which the Score object is to be written.
    @param score The variable containing the Score object to be written.
    @pre outputStream is open and ready for writing.
    @post An object of type Score has been written out and <tt>outputStream</tt>
    is still open.
    */

public:
    Score();
    /**<
    Default constructor. Creates an empty Score object.
    */

    Score
        (
        const string& s //in
        );
    /**<
    Constructor. Creates a Score object containing the digits in s.
    No error checking for score validity is performed during construction
    but <tt>isValid()</tt> can be used after the fact to ascertain validity.
    */

    bool isValid() const;
    /**<
    Returns <tt>true</tt>, if this Score object represents a valid score,
    and <tt>false</tt> otherwise. A valid score contains exactly 2 digits,
    each one in the range 0..4. Also, the sum of the digits must not exceed
    4, and a score of 31 is also invalid.
    */

    bool operator==
        (
        const Score& otherScore //in
        ) const;
    /**<
    Tests whether this Score object is the same as the otherScore
    object, that is, whether they each contain 2 digits and those
    digits are the same and in the same order in both Score objects.
    */

    bool operator!=
        (
        const Score& otherScore //in
        ) const;
    /**<
    Tests whether this Score object is not equal to the otherScore
    object. Returns true if operator== returns false, and false if
    operator== returns true.
    */

private:
    string digits;
};

#endif
