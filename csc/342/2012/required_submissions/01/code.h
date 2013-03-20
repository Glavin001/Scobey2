//code.h

#ifndef CODE_H
#define CODE_H

#include <string>
using namespace std;

#include "utilities.h"
using Scobey::RandomGenerator;

#include "score.h"

/**
A class of 4-digit codes for use in a guessing game that pits
the computer as codebreaker against the user as codemaker.
*/
class Code
{
friend istream& operator>>
    (
        istream& inputStream, //inout
        Code& code            //out
    );
    /**<
    Reads a Code object from the input stream.
    @param inputStream The stream from which the Code object is to be read.
    @param code The receiving variable for the Code object.
    @pre inputStream is open and ready for reading.
    @post An object of type Code has been read in and <tt>inputStream</tt>
    is still open.
    */

friend ostream& operator<<
    (
        ostream& outputStream, //inout
        const Code& code       //in
    );
    /**<
    Writes a Code object to an output stream.
    @param outputStream The stream to which the Code object is to be written.
    @param code The variable containing the Code object to be written.
    @pre outputStream is open and ready for writing.
    @post An object of type Code has been written out and <tt>outputStream</tt>
    is still open.
    */

public:
    Code();
    /**<
    Default constructor. Creates an empty Code object.
    */

    Code
        (
        const string& s
        );
    /**<
    Constructor. Creates a Code object containing the digits in s.
    No error checking for code validity is performed during construction
    but isValid() can be used after the fact to ascertain validity.
    */

    void initialize();
    /**<
    Permits the user to enter a Code object (to be used as a starting
    guess, for example) or chooses one at random if the user opts not
    to enter one. A randomly generated code is guaranteed to be valid.
    A code entered by the user may or may not be valid.
    @pre None.
    @post The following prompt has been displayed:
<pre>
Enter starting guess here, or just press Enter to generate a random one:
</pre>
     A code has been entered by the user, or randomly generated.
    */

    bool isValid() const;
    /**<
    Returns <tt>true</tt> if this Code object represents a valid code,
    and <tt>false</tt> otherwise. A valid code is one containing exactly
    4 digits, each one in the range 1..8, with repetition allowed.
    */

    Score scoreAgainst
    (
        const Code& otherCode //in
    ) const;
    /**<
    Computes and returns a Score object representing the score of this
    Code object when scored against the <tt>otherCode</tt> object.
    @return The score when this code is scored agains <tt>otherCode</tt>.
    @param otherCode The other code against which this code is being scored.
    @pre <tt>otherCode</tt> has been initialized.
    @post The score of this Code object against <tt>otherCode</tt> has been
    returned.
    */

    void increment();
    /**<
    Changes the value of this Code object to the value following
    this Code object, with 8888 wrapping to 1111.
    */

    void decrement();
    /**<
    Changes the value of this Code object to the value preceding
    this Code object, with 1111 wrapping to 8888.
    */

    bool operator==
        (
        const Code& otherCode //in
        ) const;
    /**<
    Tests whether this Code object is the same as the <tt>otherCode</tt>
    object. That is, tests whether each Code object contains 4 digits, and
    those digits are the same and in the same order in each Code object.
    */

    bool operator<
        (
        const Code& otherCode //in
        ) const;
    /**<
    Tests whether this Code object precedes the <tt>otherCode</tt> object.
    This is determined by the lexicograpic (alphabetic) ordering of the
    digit strings in the two Code objects.
    */

private:
    static const int CODE_SIZE = 4;
    string digits;
    RandomGenerator g;
};

#endif
