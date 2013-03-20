//calculator_shell.hpp
//Lastname:Firstname:A00123456:csc34101
//Submission 07
//Implementing a Simple Four-Function Calculator

enum TagType
/**
A type used for labeling the data content of a binary expression tree node.
*/
{
    INT_ONLY,
    SUB_NODE
};


struct TreeNode
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
            TreeNode* left;
            char op;
            TreeNode* right;
        };
    };
};


/*************************************************************************
If you need, or would like to have, any "helper" functions, put their
prototypes here, complete with doxygen-style documentation.
*************************************************************************/

void GetExpression
(
    istringstream& inStream, //inout
    TreeNode& eTree,         //out
    bool& successful         //out
);
/**<
Tries to read a valid expression from the input stream and construct 
the corresponding expression tree.
@param inStream The stream from which the expression is being read.
@param eTree Where the expression is stored if the function succeeds.
@param successful Indicates whether a valid expression has been read.
@pre inStream has been initiallzed and is available for reading.
@post If successful is true, the function has succeeded, eTree contains
a valid expression tree, and inStream is still available for reading.
If successful is false, the function has failed, and both inStream and
eTree are in an undefined state.
*/


void CheckForGarbage
(
    istringstream& inStream, //inout
    bool& successful         //out
);
/**<
Determines if there are any remaining non blank space characters
in the input stream.
@param inStream The input source stream.
@param successful true if any characters that are not blank spaces
are seen before the end of the input stream, and otherwise false.
@pre inStream has been ininitalized and is open.
@post All blank spaces on the input line up to the first non blank
space have been consumed.
*/


int expressionValue
(
    const TreeNode& eTree //in
);
/**<
Evaluates an arithmetic expression stored in a binary expression tree.
Called only by main.
@param eTree Where the arithmetic expression is stored.
@return Compute the numerical value of the arithmetic expression
stored in eTree.
@pre eTree contains a valid arithmetic expression.
@post The value of the arithmetic expression in eTree has been returned.
*/


void DisplayExpression
(
    const TreeNode& eTree //in
);
/**<
Displays an arithmetic expression stored in a binary expression tree.
Called only by main.
@param eTree Where the arithmetic expression is stored.
@pre eTree contains a valid arithmetic expression.
@post The expression in eTree has been displayed, in fully parenthesized
form, with a blank space on either side of each operator.
*/


/*************************************************************************
If you provided any "helper" function prototypes above, put the function
definitions corresponding to those prototypes here.
*************************************************************************/

void GetExpression
(
    istringstream& inStream, //inout
    TreeNode& eTree,         //out
    bool& successful         //out
)
{
    //Fill in the body ...
}


void CheckForGarbage
(
    istringstream& inStream, //inout
    bool& successful         //out
)
{
    //Fill in the body ...
}


int expressionValue
(
    const TreeNode& eTree //in
)
{
    //Fill in the body ...
}


void DisplayExpression
(
    const TreeNode& eTree //in
)
{
    //Fill in the body ...
}
