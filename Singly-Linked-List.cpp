// SINGLY LINKED LIST PROGRAM

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linkedList : public node
{
    node *head, *last, *n2;

public:
    linkedList()
    {
        head = last = NULL; // list is empty
    }

    void create()
    {
        node *temp = new node; //dynamic memory allocation
        int d;
        cout << "\nEnter the data: ";
        cin >> d;
        temp->data = d;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp; //pointing to first node
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    void insert()
    {
        node *temp = new node;
        node *prev = NULL;
        node *curr = head;
        int count = 1, pos, ch, d;
        cout << "\nEnter data: ";
        cin >> d;
        temp->data = d;
        temp->next = NULL;
        cout << "\nINSERT AS\n1) FIRST NODE\n2) LAST NODE\n3) IN BETWEEN";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            temp->next = head; // attach newly created node with previous first node
            head = temp;       // assigned head to the newly created first node
            break;

        case 2:
            last->next = temp; // Attach new node at the end
            last = temp;       // assign last to the end node
            break;

        case 3:
            cout << "\n Enter the position you want to insert node: ";
            cin >> pos;
            while (count != pos)
            {
                prev = curr;       // prev is equal to pos
                curr = curr->next; // curr is pos+1
                count++;
            }
            if (count == pos)
            {
                prev->next = temp;
                temp->next = curr;
            }
            break;
        }
    }

    void del()
    {
        node *prev = NULL;
        node *curr = head;
        int count = 1, pos, ch;
        cout << "\nDELETE\n1) FIRST NODE\n2) LAST NODE\n3) IN BETWEEN";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (head != NULL)
            {
                cout << "\nDeleted node is: " << head->data << endl;
                head = head->next;
            }
            break;
        case 2:
            while (curr != last)
            {
                prev = curr;
                curr = curr->next;
            }
            if (curr == last)
            {
                cout << "\ndeleted node is: " << curr->data;
                prev->next = NULL;
                last = prev;
            }
            break;
        case 3:
            cout << "\n Enter the position you want to delete node: ";
            cin >> pos;
            while (count != pos)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            if (count == pos)
            {
                cout << "\nDeleted node is: " << curr->data << endl;
                prev->next = curr->next;
            }
        }
    }

    void reverse()
    {
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next; // reverse current node's pointer
            curr->next = prev; // move pointers one position ahead
            prev = curr;       //swapping
            curr = next;       //swapping of roles
        }
        head = prev;
    }

    void seclist()
    {
        int ch;
        cout << "Pls create a 2nd list: " << endl;
        cout << "How many nodes would you like to append: ";
        cin >> ch;
        for (int i = 1; i <= ch; i++)
        {
            create();
        }
    }

    void con(linkedList l1)
    {
        node *x = head;
        node *y = l1.head;
        node *temp = head;
        while (x->next != NULL)
        {
            x = x->next;
        }
        x->next = y;
    }

    void display()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "\n List is empty";
        }
        cout << "\nList is: ";
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    int ch, n;
    linkedList l, l1;
    while (1)
    {
        cout << endl
             << "\n##### MENU #####";
        cout << "\n1) CREATE\n2) INSERT\n3) DELETE\n4) REVERSE\n5) CONCATENATE\n6) EXIT\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter number of nodes you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                l.create();
            l.display();
            break;
        case 2:
            l.insert();
            l.display();
            break;
        case 3:
            l.del();
            l.display();
            break;
        case 4:
            l.reverse();
            l.display();
            break;
        case 5:
            l1.seclist();
            l1.display();
            l.con(l1);
            cout << "\n\nConcatenated list is: ";
            l.display();
            break;
        case 6:
            break;
        }
    }
    return 0;
}