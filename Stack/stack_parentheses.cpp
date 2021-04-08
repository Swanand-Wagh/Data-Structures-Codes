#include <iostream>
#include <string.h>
using namespace std;

char st[20];
int top = -1;

void push(char a)
{
	top++;
	st[top] = a;
}
char pop()
{
	return st[top--];
}

int main()
{
	system("cls");
	char a[20], t;
	int i, f = 1;
	cout << "Enter parentheses: ";
	gets(a);
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == '(' || a[i] == '{' || a[i] == '[')
			push(a[i]);
		if (a[i] == ')' || a[i] == '}' || a[i] == ']')
		{
			if (top == -1)
				f = 0;
			else
			{
				t = pop();
				if (a[i] == ')' && (t == '[' || t == '{'))
					f = 0;
				if (a[i] == '}' && (t == '(' || t == '['))
					f = 0;
				if (a[i] == ']' && (t == '{' || t == '('))
					f = 0;
			}
		}
	}
	if (top >= 0)
		f = 0;
	if (f == 0)
		cout << "Unbalanced Parentheses";
	else
		cout << "Balanced Parentheses";
	return 0;
}
