// CIRCULAR LINKED LIST PROGRAM

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class CircularLinkedList : public node
{
    node *head;

public:
    CircularLinkedList()
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

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            temp->next = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    void insert()
    {
        node *temp = new node;
        node *ptr = head;
        int count = 2, pos, ch, d;

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
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
            head = temp;
            break;

        case 2:
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
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
                ptr->next = temp;
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
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            cout << "\nDeleted first node is: " << head->data << endl;
            head = head->next;
            break;

        case 2:
            while (ptr->next != head)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            cout << "\nDeleted last node is: " << ptr->data << endl;
            prev->next = head;
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
                cout << "\nDeleted middle node is: " << ptr->data << endl;
                prev->next = ptr->next;
            }
            break;

        default:
            cout << "Invalid Choice!";
        }
    }

    void reverse()
    {
        node *ptr = head;
        node *prev = NULL;
        node *nex = NULL;
        do
        {
            nex = ptr->next;
            ptr->next = prev; // link reverses
            prev = ptr;       // prev moves one pos ahead
            ptr = nex;        // ptr moves one pos ahead
        } while (ptr != head);
        head->next = prev;
        head = prev;
    }

    void con(CircularLinkedList l1)
    {
        node *ptr1 = head;
        node *ptr2 = l1.head;
        while (ptr1->next != head)
        {
            ptr1 = ptr1->next;
        }
        ptr1->next = ptr2;
        while (ptr2->next != l1.head)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = head;
    }

    void display()
    {
        if (head == NULL)
            cout << "No Nodes in Circular Linked List";
        else
        {
            cout << "\nCircular Linked List: ";
            cout << "\nHead: " << head->data << endl;
            node *temp = head;
            do
            {
                cout << "[ " << temp->data << " ] --> ";
                temp = temp->next;
            } while (temp != head);
            cout << "[ " << head->data << " ]";
        }
    }
};

int main()
{
    system("cls");
    int ch, n;
    CircularLinkedList l, l1;
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