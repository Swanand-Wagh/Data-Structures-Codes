// BINARY SEARCH TREE PROGRAM + SEARCH & DELETE NODE

#include <iostream>
using namespace std;
#define SPACE 10

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

class BinarySearchTree
{
public:
  TreeNode *root;
  BinarySearchTree()
  {
    root = NULL;
  }

  bool isTreeEmpty()
  {
    if (root == NULL)
      return true;
    else
      return false;
  }

  void insertNode(TreeNode *new_node)
  {
    if (root == NULL)
    {
      root = new_node;
      cout << "Data Inserted as root node!" << endl;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (new_node->data == temp->data)
        {
          cout << "Data Already exists, Insert another data!" << endl;
          return;
        }
        else if ((new_node->data < temp->data) && (temp->left == NULL))
        {
          temp->left = new_node;
          cout << "Data Inserted to the left!" << endl;
          break;
        }
        else if (new_node->data < temp->data)
          temp = temp->left;
        else if ((new_node->data > temp->data) && (temp->right == NULL))
        {
          temp->right = new_node;
          cout << "Data Inserted to the right!" << endl;
          break;
        }
        else
          temp = temp->right;
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

  void SearchNode(int d)
  {
    TreeNode *temp = root;
    int cnt = 0;

    if (root == NULL)
    {
      cout << "\nBST is Empty!\n\n";
      return;
    }
    else
    {
      while (temp != NULL)
      {
        if (d == temp->data)
        {
          cout << "\nValue found!\n\n";
          return;
        }
        else if (d < temp->data)
          temp = temp->left;
        else if (d > temp->data)
          temp = temp->right;
      }
    }
    if (cnt == 0)
      cout << "\nValue is not present in the BST!\n\n";
  }
};

int main()
{
  system("cls");
  BinarySearchTree obj;
  int option, d;
  do
  {
    cout << "What operation do you want to perform? "
         << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "Enter option: ";
    cin >> option;
    TreeNode *new_node = new TreeNode();

    switch (option)
    {
    case 0:
      exit(0);

    case 1:
      cout << "\nINSERT" << endl;
      cout << "Enter data of TREE NODE to INSERT in BST: ";
      cin >> d;
      new_node->data = d;

      obj.insertNode(new_node);
      obj.print2D(obj.root, 5);
      cout << endl;
      break;

    case 2:
      int val;
      cout << "Enter value to search in the BST: ";
      cin >> val;
      obj.SearchNode(val);
      break;

    case 3:
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
  return 0;
}