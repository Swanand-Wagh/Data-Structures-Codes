// BINARY SEARCH TREE PROGRAM + SEARCH & DELETE NODE

#include <iostream>
using namespace std;
#define SPACE 10
int cnt = 0;

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

  void displayTree(TreeNode *r, int space)
  {
    if (r == NULL) // Base case
      return;
    space += SPACE;               // Increase distance between levels
    displayTree(r->right, space); // Process right child first
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " ";
    cout << r->data << "\n";
    displayTree(r->left, space); // Process left child
  }

  void SearchNode(int d)
  {
    TreeNode *temp = root;

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
          cnt = 1;
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

  TreeNode *MinValueNode(TreeNode *node)
  {
    TreeNode *current = node;

    while (current->left != NULL) /* loop down to find the leftmost leaf */
      current = current->left;

    return current;
  }

  TreeNode *DeleteNode(TreeNode *r, int v)
  {
    // base case empty condition
    if (r == NULL)
      return NULL;
    // If the data to be deleted is smaller than the root's data, then it lies in left subtree
    else if (v < r->data)
      r->left = DeleteNode(r->left, v);
    // If the data to be deleted is greater than the root's data, then it lies in right subtree
    else if (v > r->data)
      r->right = DeleteNode(r->right, v);
    // if data is same as root's data, then This is the node to be deleted
    else
    {
      // node with only one child or no child
      if (r->left == NULL) // has a right child
      {
        TreeNode *temp = r->right;
        delete r;
        return temp;
      }
      else if (r->right == NULL) // has a left child
      {
        TreeNode *temp = r->left;
        delete r;
        return temp;
      }
      else
      {
        // node with 2 children: Get the In-Order successor (smallest in the right subtree)
        TreeNode *temp = MinValueNode(r->right);
        // Copy the inorder successor's content to this node
        r->data = temp->data;
        // Delete the inorder successor
        r->right = DeleteNode(r->right, temp->data);
        //deleteNode(r->right, temp->value);
      }
    }
    return r;
  }
};

int main()
{
  system("cls");
  BinarySearchTree obj;
  int option, d, val;
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
      obj.displayTree(obj.root, 5);
      cout << endl;
      break;

    case 2:
      cout << "Enter value to search in the BST: ";
      cin >> val;
      obj.SearchNode(val);
      break;

    case 3:
      cout << "\nDELETE" << endl;
      cout << "Enter Value to Delete from BST: ";
      cin >> val;

      obj.SearchNode(val);
      if (cnt != 0)
      {
        obj.DeleteNode(obj.root, val);
        cout << "Node having Value " << val << " has been Deleted!" << endl;
        obj.displayTree(obj.root, 5);
        cout << endl;
      }
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
  return 0;
}