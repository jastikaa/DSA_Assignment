#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 100
char opStack[MAX];
int topOp = -1;

int valStack[MAX];
int topVal = -1;

void pushOp(char ch) {
    opStack[++topOp] = ch;
}
char popOp() {
    return opStack[topOp--];
}
char peekOp() {
    return opStack[topOp];
}
int isEmptyOp() {
    return topOp == -1;
}

void pushVal(int val) {
    valStack[++topVal] = val;
}

int popVal() {
    return valStack[topVal--];
}

int precedence(char op) {
    if (op=='+' || op=='-') return 1;
    if (op=='*' || op=='/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    while (infix[i]) {
        if (isspace(infix[i])) {
            i++;
            continue;
        }
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
        } else if (infix[i] == '(') {
            pushOp(infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmptyOp() && peekOp() != '(') {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            popOp(); 
            i++;
        } else {
            while (!isEmptyOp() && precedence(peekOp()) >= precedence(infix[i])) {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            pushOp(infix[i++]);
        }
    }

    while (!isEmptyOp()) {
        postfix[k++] = popOp();
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}
int evaluatePostfix(char* postfix) {
    int i = 0;
    while (postfix[i]) {
        if (isspace(postfix[i])) {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');
            }
            pushVal(num);
        } else {
            int b = popVal();
            int a = popVal();
            int res = applyOp(a, b, postfix[i]);
            pushVal(res);
            i++;
        }
    }
    return popVal();
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression for conversion:\n");
    fgets(infix, MAX, stdin);
    infix [strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix Expression is: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result after calculation: %d\n", result);
    return 0;
}