// BINARY TREE PROGRAM + IN-ORDER / PRE-ORDER / POST-ORDER TREE TRAVERSALS

#include <iostream>
using namespace std;
#define SPACE 10

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
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
            cout << "Value Inserted as root node!" << endl;
        }
        else
        {
            int ch;
            TreeNode *temp = root;
            while (1)
            {
                cout << "Left or right (1/2) of " << temp->value << "? : ";
                cin >> ch;

                if (ch == 1)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        cout << "Value Inserted to the left!" << endl;
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
                        cout << "Value Inserted to the right!" << endl;
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
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value << "\n";           // 6
        print2D(r->left, space);            // Process left child  7
    }

    void printPreorder(TreeNode *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        printInorder(r->right);
    }

    void printPostorder(TreeNode *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree
        printPostorder(r->left);
        // then recur on right subtree
        printPostorder(r->right);
        // now deal with the node
        cout << r->value << " ";
    }
};

int main()
{
    system("cls");
    BinaryTree obj;
    int option, val;
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
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
            obj.insertNode(new_node);
            cout << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            break;

        case 2:
            cout << "In-Order Traversal: ";
            obj.printInorder(obj.root);
            cout << endl;
            break;

        case 3:
            cout << "Pre-Order Traversal: ";
            obj.printPreorder(obj.root);
            cout << endl;
            break;

        case 4:
            cout << "Post-Order Traversal: ";
            obj.printPostorder(obj.root);
            cout << endl;
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}