// BINARY SEARCH TREE PROGRAM + SEARCH & DELETE NODE

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
      cout << "Value Inserted as root node!" << endl;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (new_node->value == temp->value)
        {
          cout << "Value Already exist,"
               << "Insert another value!" << endl;
          return;
        }
        else if ((new_node->value < temp->value) && (temp->left == NULL))
        {
          temp->left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }
        else if (new_node->value < temp->value)
          temp = temp->left;
        else if ((new_node->value > temp->value) && (temp->right == NULL))
        {
          temp->right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }
        else
          temp = temp->right;
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
      cout << " ";                      // 5.1
    cout << r->value << "\n";           // 6
    print2D(r->left, space);            // Process left child  7
  }
};

int main()
{
  system("cls");
  BinarySearchTree obj;
  int option, val;
  do
  {
    cout << "What operation do you want to perform? "
         << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Create Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "Enter option: ";
    cin >> option;
    TreeNode *new_node = new TreeNode();

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "\nINSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
      cin >> val;
      new_node->value = val;
      obj.insertNode(new_node);
      obj.print2D(obj.root, 5);
      cout << endl;
      break;

    case 2:
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
  return 0;
}