#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Fungsi-fungsi stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // Tanda khusus untuk menandai stack kosong
}

// Fungsi konversi dari infiks ke postfiks
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack) return;

    for (i = 0, k = -1; exp[i]; ++i) {
        if (isalnum(exp[i])) {
            exp[++k] = exp[i];
        } else if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                exp[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) {
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack)) {
        exp[++k] = pop(stack);
    }

    exp[++k] = '\0';
    printf("Ekspresi postfiks: %s\n", exp);
}

// Fungsi utama
int main() {
    char exp[100];
    printf("Masukkan ekspresi infiks: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}

