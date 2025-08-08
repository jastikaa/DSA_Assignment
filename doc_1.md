#Question 1: Check for Balanced Parentheses Using Stack

##(a) Data structure defination

A stack data structure is also used in the program as a means of verifying parentheses balancing in given mathematical expression.

#define MAX 100
char stack[MAX];
int top = -1;

1. stack[MAX] is a character array that holds up to 100 characters.

2. Top keeps track of the current top position of stack.

2.1  In case of top == -1, the stack is empty.

2.2 When we push an element, we increase top.

2.3 When we pop, we return the element at top and then decrement it.

The stack is used to store opening brackets (, {, [ when they appear in the expression. When a closing bracket is encountered, it checks the stack to find a matching pair.

##(b) Description of the Functions Implemented
1. void push(char ch)
Purpose: Pushes a character (ch) onto the stack if there’s space.
this ia applied in case of opening bracket is found.

2. char pop()
Purpose:  It pops the top character from the stack and return it.
It is used if closing bracket is found, to match with the last opening bracket.

3. char peek()
Purpose: Returns the top element of the stack without removing it.
It is not directly employed in this code but generally useful in stack operations.

4. int isMatchingPair(char opening, char closing)
Purpose: Returns 1 (true) if opening and closing brackets form a valid pair.
Matches (), {}, and [].

5. int isBalanced(char *expr)
Purpose: To check if the given expression expr has balanced brackets or not.

Logic:
Walk along the expression character by character.
Push opening brackets onto the stack.

For closing brackets:
Pop from the stack and check if it matches using isMatchingPair.
If unmatched or stack is empty during the pop, return not balanced.
At last, return true if the stack is empty (i.e., all brackets matched).

##(c) An Overview of How the main() Method Is Organized
The main() function performs the following:

Initializes an array of test expressions:
char *expressions[] = {
    "a + (b - c) * (d",
    "m + [a - b * (c + d * {m)]",
    "a + (b - c)"
};
Iterates over each expression using a for loop.

Calls isBalanced() for each expression.

Prints whether each expression is Balanced or Not Balanced.

##(d) Output of a Complete Run of the Program
mathematical
Expression: a + (b - c) * (d
Not Balanced 

Expression: m + [a - b * (c + d * {m)]
Not Balanced 

Expression: a + (b - c)
Balanced 

##(e)Conclusion
This program effectively applies a stack to check for balance parenthesis, brackets and braces in mathematical expression. It addresses such common edge cases as a lack of closing or opening bracket, nested expressions and various types of brackets.