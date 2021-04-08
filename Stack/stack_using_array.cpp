#include <iostream>
using namespace std;

int stack[100], choice, n, top, x, i;

void display()
{
    cout << "\ntop(index): " << top;
    cout
        << "\ntop(value): " << stack[top];
    if (top >= 0)
    {
        cout << "\nThe elements in STACK \n";
        for (i = top; i >= 0; i--)
            cout << "\n"
                 << stack[i];
    }
    else
        cout << "\nThe STACK is empty";
    cout << "\n";
}
void push()
{
    if (top >= n - 1)
        cout << "\nSTACK is full";
    else
    {
        cout << "Enter a value to be pushed: ";
        cin >> x;
        top++;
        stack[top] = x;
        display();
    }
}
void pop()
{
    if (top <= -1)
        cout << "\nStack is empty";
    else
    {
        cout << "\nThe popped element is " << stack[top];
        top--;
        display();
    }
}

int main()
{
    system("cls");
    top = -1;

    cout << "Enter the size of STACK: ";
    cin >> n;
    do
    {
        cout << "\n1.PUSH\n2.POP\n3.EXIT\nEnter: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            cout << "\nEXIT";
            break;

        default:
            cout << "\nPlease Enter a Valid Choice(1/2/3)";
        }
    } while (choice != 3);
    return 0;
}
