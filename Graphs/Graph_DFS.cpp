#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void create();
void display();
void dfs();

struct node
{
    int data, status;
    struct node *next;
    struct link *adj;
};

struct link
{
    struct node *next;
    struct link *adj;
};

struct node *start, *p, *q;

struct link *l, *k;

int cnt = 0;

int main()
{
    int choice;
    while (1)
    {
        cout << "\n1: CREATE\n2: DISPLAY\n3: DFS\n4: EXIT\n";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            create();
            cnt = 1;
            break;
        case 2:
            if (cnt == 0)
            {
                cout << "Graph empty!!";
            }
            else
                display();
            break;
        case 3:
            if (cnt == 0)
            {
                cout << "Graph empty!!";
            }
            else
                dfs();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Input!!";
            getch();
        }
    }
    return 0;
}

void create()
{
    int dat, flag = 0;
    start = NULL;
    cout << "Enter the nodes in the graph(0 to end): ";
    while (1)
    {
        cin >> dat;
        if (dat == 0)
            break;
        p = new node;
        p->data = dat;
        p->status = 0;
        p->next = NULL;
        p->adj = NULL;
        if (flag == 0)
        {
            start = p;
            q = p;
            flag++;
        }
        else
        {
            q->next = p;
            q = p;
        }
    }
    p = start;
    while (p != NULL)
    {
        cout << "Enter the links to " << p->data << " (press 0 to end):";
        flag = 0;
        while (1)
        {
            cin >> dat;
            if (dat == 0)
                break;
            q = start;
            int flag1 = 0;
            while (q != NULL)
            {
                if (q->data == dat)
                {
                    flag1 = 1;
                    k = new link;
                    k->next = q;
                    k->adj = NULL;
                    if (flag == 0) // empty
                    {
                        p->adj = k;
                        l = k;
                        flag++;
                    }
                    else
                    {
                        l->adj = k;
                        l = k;
                    }
                }
                q = q->next;
            }
            if (flag1 == 0)
                cout << "Element to link not found!!";
        }
        p = p->next;
    }
    return;
}

void display()
{
    node *temp = start;
    link *templ = temp->adj;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        templ = temp->adj;
        while (templ != NULL)
        {
            cout << templ->next->data << " --> ";
            templ = templ->adj;
        }
        temp = temp->next;
        cout << "NULL" << endl;
    }
}

void dfs()
{
    int stack[25], top = 1;
    cout << "\nDFS Traversal:";
    p = start;
    while (p != NULL)
    {
        p->status = 0; // visited or not
        p = p->next;
    }
    p = start;
    stack[0] = 0;
    stack[top] = p->data;
    p->status = 1;
    while (1)
    {
        if (stack[top] == 0)
            break;
        p = start;
        while (p != NULL)
        {
            if (p->data == stack[top])
                break;
            p = p->next;
        }
        cout << stack[top] << "  ";
        top--;
        k = p->adj;
        while (k != NULL)
        {
            q = k->next;
            if (q->status == 0)
            {
                top++;
                stack[top] = q->data;
                q->status = 1;
            }
            k = k->adj;
        }
    }
    getch();
    return;
}