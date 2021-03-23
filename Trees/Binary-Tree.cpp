// BINARY TREE PROGRAM + IN-ORDER / PRE-ORDER / POST-ORDER TREE TRAVERSALS

#include <iostream>
using namespace std;
#define SPACE 10
#define MAX 100

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class stack : public TreeNode
{
    int top;
    TreeNode *item[MAX];

public:
    stack() { top = -1; }

    void push(TreeNode *p) { item[++top] = p; }

    TreeNode *pop() { return item[top--]; }

    int isfull() { return top == MAX; }

    int isempty() { return top == -1; }

    TreeNode *peek() { return item[top]; }
};

class BinaryTree : public TreeNode
{
public:
    TreeNode *root;
    BinaryTree()
    {
        root = NULL;
    }

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "data Inserted as root node!" << endl;
        }
        else
        {
            int ch;
            TreeNode *temp = root;
            while (1)
            {
                cout << "Left or right (1/2) of " << temp->data << "? : ";
                cin >> ch;

                if (ch == 1)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        cout << "data Inserted to the left!" << endl;
                        break;
                    }
                    else
                        temp = temp->left;
                }
                else if (ch == 2)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new_node;
                        cout << "data Inserted to the right!" << endl;
                        break;
                    }
                    else
                        temp = temp->right;
                }
                else
                    cout << "Wrong Choice!";
            }
        }
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case
            return;
        space += SPACE;           // Increase distance between levels
        print2D(r->right, space); // Process right child first
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->data << "\n";
        print2D(r->left, space); // Process left child
    }

    void printPreorder(TreeNode *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        cout << r->data << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        printInorder(r->left);
        cout << r->data << " ";
        printInorder(r->right);
    }

    void printPostorder(TreeNode *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->data << " ";
    }

    void IterativePreOrder()
    {
        TreeNode *temp = root;
        stack s;
        while (1)
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                s.push(temp);
                temp = temp->left;
            }
            if (s.isempty())
                break;
            temp = s.pop();
            temp = temp->right;
        }
    }

    void IterativeInOrder()
    {
        TreeNode *temp = root;
        stack s;
        while (1)
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            if (s.isempty())
                break;
            temp = s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    void IterativePostOrder()
    {
        TreeNode *temp = root;
        TreeNode *q;
        stack s;
        while (1)
        {
            while (temp != NULL)
            {
                if (temp->right)
                    s.push(temp->right);
                s.push(temp);
                temp = temp->left;
            }
            temp = s.pop();
            if (temp->right && s.peek() == temp->right)
            {
                q = s.pop();
                s.push(temp);
                temp = temp->right;
                continue;
            }
            cout << temp->data << " ";
            temp = NULL;
            if (s.isempty())
                break;
        }
    }
};

int main()
{
    system("cls");
    BinaryTree obj;
    int option, d, ch;
    do
    {
        cout << "\nWhat operation do you want to perform? "
             << endl;
        cout << "0. Exit Program" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Print In-Order Traversal" << endl;
        cout << "3. Print Pre-Order Traversal" << endl;
        cout << "4. Print Post-Order Traversal" << endl;
        cout << "Enter option: ";
        cin >> option;
        cout << endl;
        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            exit(0);

        case 1:
            cout << "\nINSERT" << endl;
            cout << "Enter data of TREE NODE to INSERT in Binary Tree: ";
            cin >> d;
            new_node->data = d;

            obj.insertNode(new_node);
            cout << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            break;

        case 2:
            cout << "1. Recursive In-Order Traversal\n2. Iterative In-Order Traversal\nEnter Choice: ";
            cin >> ch;
            cout << "\nIn-Order Traversal: ";

            if (ch == 1)
            {
                obj.printInorder(obj.root);
                cout << endl;
            }
            else
            {
                obj.IterativeInOrder();
                cout << endl;
            }
            break;

        case 3:
            cout << "1. Recursive Pre-Order Traversal\n2. Iterative Pre-Order Traversal\nEnter Choice: ";
            cin >> ch;
            cout << "\nPre-Order Traversal: ";

            if (ch == 1)
            {
                obj.printPreorder(obj.root);
                cout << endl;
            }
            else
            {
                obj.IterativePreOrder();
                cout << endl;
            }
            break;

        case 4:
            cout << "1. Recursive Post-Order Traversal\n2. Iterative Post-Order Traversal\nEnter Choice: ";
            cin >> ch;
            cout << "\nPost-Order Traversal: ";

            if (ch == 1)
            {
                obj.printPostorder(obj.root);
                cout << endl;
            }
            else
            {
                obj.IterativePostOrder();
                cout << endl;
            }
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}