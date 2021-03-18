// DOUBLY LINKED LIST PROGRAM

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;
};

class DoublyLinkedList : public node
{
    node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void create()
    {
        node *temp = new node; //dynamic memory allocation
        node *ptr = head;
        int d;

        cout << "\nEnter the data: ";
        cin >> d;
        temp->data = d;
        temp->next = NULL;
        temp->previous = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->previous = ptr;
        }
    }

    void insert()
    {
        node *temp = new node;
        int count = 2, pos, ch, d;
        node *ptr = head;

        cout << "\nEnter data: ";
        cin >> d;
        temp->data = d;
        temp->next = NULL;
        temp->previous = NULL;

        cout << "\nINSERT AS\n1) FIRST NODE\n2) LAST NODE\n3) IN BETWEEN";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            head->previous = temp;
            temp->next = head;
            head = temp;
            break;

        case 2:
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->previous = ptr;
            break;

        case 3:
            cout << "\nEnter the position you want to insert node: ";
            cin >> pos;
            while (count != pos)
            {
                ptr = ptr->next;
                count++;
            }
            if (count == pos)
            {
                temp->next = ptr->next;
                ptr->next->previous = temp;
                ptr->next = temp;
                temp->previous = ptr;
            }
            break;

        default:
            cout << "Invalid Choice!";
        }
    }

    void del()
    {
        node *ptr = head;
        node *prev = NULL;
        int count = 1, pos, ch;

        cout << "\nDELETE AS\n1) FIRST NODE\n2) LAST NODE\n3) IN BETWEEN";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            head->next->previous = NULL;
            head = head->next;
            break;

        case 2:
            while (ptr->next != NULL)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            // ptr->previous->next = NULL;
            prev->next = NULL;
            break;

        case 3:
            cout << "\nEnter the position you want to delete node: ";
            cin >> pos;
            while (count != pos)
            {
                prev = ptr;
                ptr = ptr->next;
                count++;
            }
            if (count == pos)
            {
                prev->next = ptr->next;
                ptr->next->previous = prev;
            }
            break;

        default:
            cout << "Invalid Choice!";
        }
    }

    void reverse()
    {
        node *current = head;
        node *prev = NULL, *nxt = NULL;

        while (current != NULL)
        {
            nxt = current->next;  // Reverse current node's pointer
            current->next = prev; // Move pointers one position ahead.
            prev = current;
            current = nxt;
        }
        head = prev;
    }

    void con(DoublyLinkedList l1)
    {
        node *ptr1 = head;
        node *ptr2 = l1.head;
        while (ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
        }
        ptr1->next = ptr2;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Doubly Linked List";
        }
        else
        {
            node *temp = head;
            cout << endl
                 << "Doubly Linked List: ";
            cout << "NULL <--> ";
            while (temp != NULL)
            {
                cout << "[ " << temp->data << " ] <--> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
};

int main()
{
    system("cls");
    int ch, n;
    DoublyLinkedList l, l1;
    while (1)
    {
        cout << endl
             << "\n########## Circular Linked List ##########";
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
            cout << "Enter number of nodes you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                l1.create();
            cout << "\nNewly Created";
            l1.display();
            l.con(l1);
            cout << "\n\nConcatenated list is: ";
            l.display();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid Choice!";
        }
    }
    return 0;
}