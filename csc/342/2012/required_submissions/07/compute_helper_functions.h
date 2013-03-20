//compute_helper_functions.h
//Specification file for the helper functions needed in the compute program.

enum TagType
/**
A type used for labeling the data content of a binary expression tree node.
*/
{
    INT_ONLY,
    SUB_NODE
};


struct NodeType
/**
The type used for the nodes of a binary expression tree.
*/
{
    TagType tag;
    union //Note that this union type is "anonymous".
    {
        int intValue;
        struct //And this struct type is also anonymous.
        {
            NodeType* left;
            char op;
            NodeType* right;
        };
    };
};


bool expressionFound
(
    istringstream& inStream, //inout
    NodeType& eTree          //out
);
/**<
Tries to read a valid expression from inStream and put it into eTree.
Called only by main() (and itself, of course, since it is recursive).
@param inStream The stream from which the expression is being read.
@param eTree Where the expression is stored if the function succeeds.
@return true if expression successfully read into eTree, otherwise false.
@pre inStream has been initiallzed and is available for reading.
@post A valid expression has been read, the function has returned true,
and inStream is still available for reading; or, the function has returned
false.
*/


bool integerFound
(
    istringstream& inStream, //inout
    int& i                   //out
);
/**<
Determines if an integer can be read next and, if so, reads and returns
the integer in i. Called only by expressionFound().
@param inStream The stream from which the integer is being read.
@param i Where the integer is stored if the function succeeds.
@return true if an integer is successfully read into i, otherwise false.
@pre inStream has been initialized and is open.
@post  The function has returned true, and inStream is still open and
available for reading; or, the function has returned false.
*/


bool expectedCharFound
(
    istringstream& inStream,       //inout
    char& ch,                      //out
    const set<char>& expectedChars //in
);
/**<
Reads a character and determines if that character is in a set of
expected characters for the current read. Called only by expressionFound().
@param inStream The stream from which the character is read.
@param ch Where the character read is stored if the function succeeds.
@param expectedChars A set of all characters that are valid for the
current read.
@return true if a character in expectedChars is read into ch,
otherwise false.
@pre expectedChars has been initialized to contain the set of all
characters that are valid for the current character read.
@post The function has returned true and inStream is still open and
available for reading; or, the function has returned false.
*/


bool garbageFound
(
    istringstream& inStream //inout
);
/**<
Determines if there are any extraneous (i.e., "garbage") characters
following a valid expression on the input line. Called only by main().
@param inStream The input source stream.
@return true if there are characters between current read cursor
location and next newline and at least one of those characters is
not a blank space, otherwise false.
@pre inStream has been ininitalized and is open.
@post A value of true has been returned if anything other than blank
spaces has been seen between the end of a valid expression on the 
input line and the newline character at the end of that line, and
false otherwise.
*/


int valueOf
(
    const NodeType& eTree //in
);
/**<
Evaluates an arithmetic expression stored in a binary expression tree.
Called only by main() (and itself, of course, since it is recursive).
@param eTree Where the arithmetic expression is stored.
@return Compute the numerical value of the arithmetic expression
stored in eTree.
@pre eTree contains a valid arithmetic expression.
@post The value of the arithmetic expression in eTree has been returned.
*/


void DisplayExpression
(
    const NodeType& eTree //in
);
/**<
Displays an arithmetic expression stored in a binary expression tree.
Called only by main() (and itself, of course, since it is recursive).
@param eTree Where the arithmetic expression is stored.
@pre eTree contains a valid arithmetic expression.
@post The expression in eTree has been displayed, in fully parenthesized
form, in a "nicely formatted" form, with a blank space on either side of
each operator.
*/
