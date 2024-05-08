#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void push(char c);
char pop();
int checkIfOperand(char);
int isOperator(char);
void postfix_To_prefix();
int prcd(char);

char str[MAX], stack[MAX];
int top = -1;
int main()
{
    postfix_To_prefix();
    return 0;
}

void push(char c)
{
    stack[++top] = c;
}
// -------------
char pop()
{
    return stack[top--];
}
// A utility function to check if the given character is operand
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
// function to check if it is an operator
int isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return 1;
    }
    return 0;
}
// ------------------
void postfix_To_prefix()
{
    int n, i, j = 0;
    char c[20];
    char a, b, op;

    printf("Enter the postfix expression\n");
    scanf("%s", &str);

    n = strlen(str);

    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Prefix expression is:\t");
    for (i = n - 1; i >= 0; i--)
    {
        if (isOperator(str[i]))
        {
            push(str[i]);
        }
        else
        {
            c[j++] = str[i];
            while ((top != -1) && (stack[top] == '#'))
            {
                a = pop();
                c[j++] = pop();
            }
            push('#');
        }
    }
    c[j] = '\0';
    char d[20];
    i = 0;
    d[n] = '\0';
    j = strlen(c) - 1;

    while (c[i] != '\0')
    {
        d[j--] = c[i++];
    }
    for (i = 0; d[i] != '\0'; i++)
        printf("%c", d[i]);
}
int prcd(char symbol) // returns the value that helps in the precedence
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '$':
    case '^':
        return 6;
        break;
    case '#':
    case '(':
    case ')':
        return 1;
        break;
    }
}