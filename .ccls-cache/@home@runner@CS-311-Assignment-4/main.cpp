#include <iostream>
#include <iomanip>
using namespace std;


struct Node{
int data;
Node* LC;
Node* RC;
Node(int key)
  {
  data = key;
  LC = NULL;
  RC = NULL;
  }
};

class BST{
private:
Node *root;
public:
BST()
{
  root = NULL;
}

void insert(int data){
  root = insert(root,data);
}

Node *insert(Node *node,int data)
{
  if(node == NULL)
  {
   node = new Node(data);
  }
  else if(node->data>data)
  {
    node->LC = insert(node->LC,data);
  }
  else if(data>node->data)
  {
    node->RC = insert(node->RC,data);
  }
  return node;
}

void treeTraversal(){
int choice = 0;
cout << "What type of tree traversal would you like to display?" << endl;
cout << "1. Pre-order 2. In-order 3. post-order" << endl;
cin >> choice;

switch(choice){
  case 1:
    preorder(root);
    break;
  case 2:
    inorder(root);
    break;
  case 3:
    postorder(root);
    break;
  default:
    cout << "Please insert a valid choice " << endl;
    break;
}
  
}

void preorder(Node* root)
{
  if(root != NULL)
  {
    cout << root->data << " ";
    preorder(root->LC);
    preorder(root->RC);
  }
}

void inorder(Node* root)
{
  if(root != NULL)
  {
    inorder(root->LC);
    cout << root->data << " ";
    inorder(root->RC); 
  }
}

void postorder(Node* root)
{
  if(root != NULL)
  {
    postorder(root->LC);
    postorder(root->RC);
    cout << root->data << " ";
  }
}

Node *search(int data){
  return search(root,data);
}

Node* search(Node* root,int data){
  if (root == NULL || root->data == data)
  {
    return root; 
  }
  
  if(root->data < data)
    return search(root->RC,data);
  return search(root->LC,data);
}
void remove(int data){
  root = remove(root,data);
}
Node* remove(Node* node,int data){
  if(node == NULL)
  {
    return node;
  }
  if(node->data>data)
  {
    node->LC =remove(node->LC, data);
  }
  else if(data>node->data)
  {
    node->RC = remove(node->RC,data);
  }
  else
  {
    if(node->LC ==NULL) // Case 1 or 2 with only 1 child
    {
      Node* temp = node->RC;
      delete node;
      return temp;
    }
    else if(node->RC == NULL)
    {
      Node* temp = node->LC;
      delete node;
      return temp;
    }
    Node* temp = rightmostNode(node->LC); // two childs
    node->data = temp->data;
    node->RC = remove(node->RC,temp->data);

  }
  return node;
}


Node* rightmostNode(Node* node){
  Node* current = node;
  while(current->RC != NULL)
    {
      current = current->RC;
    }
    return current;
}

void printNode(Node *node, int level) {
    if (node == NULL) {
        cout << string(level, ' ')  << endl;
        return;
    }
    //cout << string(level, ' ') << node->data << endl;
    printNode(node->RC, level + 1);
    cout << setw(level * 5) << node->data << endl;
    printNode(node->LC, level + 1);
}
Node* getroot(){
  return root;
}
int max(int a,int b){
  return (a > b);
}
int height(Node* node){
  if(node == NULL)
    return -1;
  //return node->height;
}
int getBalance(Node *N){
  if(N == NULL)
  {
    return 0;
  }
  return height(N->LC)-height(N->RC);
}
Node* insertavl(Node* node,int key){
  if(node == NULL)
    node = new Node(key);
  else if(key < node->data)
    node->LC = insert(node->LC,key);
  else if(key>node->data)
    node->RC = insert(node->RC,key);
  else
    return node;
  // node->height = 1 + max(height(node->LC),height(node->RC));
}
};

int main() {
int howmanyinputs;
int userinput;
BST tree;

cout << "Input your elements for the binary tree!" << endl;

string input;
getline(cin, input);
int num;
stringstream ss(input);
while (ss >> num)
{
 tree.insert(num);
}
  

Node* found = tree.search(4);
  if(found==NULL)
{
  cout << "nothing was found" << endl;
}
  else
    cout << "The node: " << found->data << " was found in the tree!"<< endl;

tree.treeTraversal();
cout << endl;
cout << "Here is your BST! (Printed side ways!)" <<endl;
tree.printNode(tree.getroot(), 0);

  
}

