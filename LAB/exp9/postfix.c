#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x);
int pop();
int evaluatePostfix(char* postfix);
int isDigit(char ch);

int main() {
    char postfix[MAX];
    
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);
    
    printf("Result of postfix evaluation: %d\n", evaluatePostfix(postfix));
    
    return 0;
}

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Error: Stack overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Error: Stack underflow\n");
        return -1;
    }
}

int isDigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    return 0;
}

int evaluatePostfix(char* postfix) {
    int i = 0, op1, op2;
    
    while (postfix[i] != '\0' && postfix[i] != '\n') {
        if (isDigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            
            switch (postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push(op1 / op2);
                    } else {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    break;
                default:
                    printf("Error: Invalid operator '%c'\n", postfix[i]);
                    return -1;
            }
        }
        i++;
    }
    
    return pop();
}


