#include <iostream>
#include <ctype.h>
using namespace std;

#define SIZE 50
char stack[SIZE];
int top = -1;

void push(char elem) /* Function for PUSH operation */
{
    stack[++top] = elem;
}

char pop() /* Function for POP operation */
{
    return (stack[top--]);
}

int priority(char symbol) /* Function for precedence */
{
    if (symbol == '^')
        return (3);
    else if (symbol == '*' || symbol == '/')
        return (2);
    else if (symbol == '+' || symbol == '-')
        return (1);
    else
        return (0);
}

int main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    cout << "Enter Infix Expression : ";
    cin >> infix;

    push('#');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop(); /* Remove ( */
        }
        else
        {
            /* Operator */
            while (priority(stack[top]) >= priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#') /* Pop from stack till empty */
        postfix[k++] = pop();

    postfix[k] = '\0'; /* Make postfix as valid string */
    cout << "\nPostfix Expression: "
         << postfix;
    return 0;
}
