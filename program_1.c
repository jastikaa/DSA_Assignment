#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; 
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isBalanced(char *expr) {
    top = -1; 
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(pop(), ch)) {
                return 0; 
            }
        }
    }
    return top == -1; 
}

int main() {
    char *expressions[] = {
        "a + (b - c) * (d",                  
        "m + [a - b * (c + d * {m)]",        
        "a + (b - c)",                      
    };

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (isBalanced(expressions[i])) {
            printf("Balanced \n\n");
        } else {
            printf("Not Balanced \n\n");
        }
    }

    return 0;
}