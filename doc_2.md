# Question 2: conversion of an infix mathematical expression to postfix and its evaluation.

## (a) Data structure defination
1. Operator Stack (opStack)
This is an array of characters used to stores operators like +, -, *, /, and parentheses ( and ). It assists to establish priorities of operation when transforming the expression to postfix form.
Such stack has a variable topOp that stores the position of the top element in stack.

2. Value Stack (valStack)
This is an integer array  that is used during the evaluation of the postfix expression.It holds temporarily numbers (operands).
The variable topVal keeps the current top index of this stack.
The both stack is implemented on the First-In-First-Out (FIFO) principle, implying that the last item that is pushed onto the stack is the first item which is popped out.

## (b) Description of the Functions Implemented

1. pushOp(char ch): Puts a parenthesis or an operator into a stack of parentseses and operators.

2. popOp(): Returns the operator at the top of the operator stack, and pops it off.

3. peekOp(): Return the top operator but does not absorb it (precedence check only).

4. isEmptyOp(): Tests theOperator stack to see whether it is empty.
pushVal(int val ): Pushes a number on the value stack.

5. popVal(): Returns and pops the top of the value stack.

6. precedence(char op): The priority level of an operator is returned. Multiplication and division take precedence over addition and subtraction (2) and vice versa.

7. applyOp(int a, int b, char op): Preforms arithmetic operation op on the numbers a and b.

8. infixToPostfix(char* infix, char* postfix): Transforms an infix expression (standard mathematical expression) to have postfix format (Reverse Polish Notation) by using the operator stack. This simplifies evaluation by using parentheses and precedence of operators.

9. evaluatePostfix(char* postfix): Accesses input numbers and operators and performs the addition, subtraction, multiplication, and division, on a value stack calculating the result of the postfix expression.

## (c) An Overview of How the main() Method Is Organized
The first is main() where the program starts its execution and determines the flow. The process by which it operates is as follows:

1. Reading Input:
The user is asked to enter an expression in infix form (such as (3 + 4) * 5 - 6 / 2) of any interest into the program. The string of expression is read in using fgets(). The fgets may insert the new line character, this cleans the input by removing the character.

2. Infix to Postfix Conversion:
The expression is then converted into a postfix in infixToPostfix() function. This operation is that of transforming the expression in infix notation (which has parentheses and operator precedence), into postfix notation (which is more readily computed programatically).

3. Presentation of Postfix Expression:
Once converted, the postfix expression appears on the screen so that the user can perceive the converted result.

4. Postfix Expression Evaluation:
The calls to the program pass the expression written in postfix form to evaluatePostfix(). This is where the value of the expression is computed, by carrying out the postfix notation.

5. Showing the Result:
Lastly the program displays the answer of the expression evaluated.

6. Program Ends:
The program sends out 0 meaning that it is successfully complete.

## (d) Output of a Complete Run of the Program

Enter the infix expression for conversion:
6+(2*1)/((3+1)*4)
Postfix Expression is: 6 2 1 * 3 1 + 4 * / +
Result after calculation: 6

## (e)Conclusion

This program sucessfully convert any legal arithmetical expression in infixed notation to postfix notation and subsequently solving the postfix expression to give a correct answer. Operators and operands are handled properly with respect to precedence and parentheses using stacks to control them. The method makes expression evaluation simple, and explains core concepts of data structures and algorithms, including stacks and parsing methods. On the whole, the program gives a real demonstration of how in computer science expressions can be processed effectively.
