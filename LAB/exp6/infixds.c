#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x);  
char pop();
int precedence(char x);
int isAlphaNumeric(char ch);
int getStringLength(char* str);
void infixToPostfix(char* infix, char* postfix);
int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);  

    infixToPostfix(infix, postfix);  
    
    printf("Postfix Expression: %s\n", postfix);  
    
    return 0;
}

void push(char x) { 
    if (top < MAX - 1) 
{
        stack[++top] = x;
    }
}


char pop() {
    if (top >= 0) 
{
        return stack[top--];
    }
    return -1; 
}
int precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;  
        case '*':
        case '/':
            return 2;  
        case '^':
            return 3;  
            return 0;  
    }
}
int isAlphaNumeric(char ch) 
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return 1; 
    }
    return 0;  
}
int getStringLength(char* str) 
{
    int length = 0;
    while (str[length] != '\0' && str[length] != '\n') {  
        length++;
    }
    return length;
}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;
    
    while (infix[i] != '\0' && infix[i] != '\n') { 
        if (isAlphaNumeric(infix[i])) {  
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {  
            push(infix[i]);
        } else if (infix[i] == ')') {  
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {  
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  
}


