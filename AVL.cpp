#include "AVL.h"
#include <iostream>
using namespace std;

NodeInterface* AVL::getRootNode() const
{
	return root;
}
bool AVL::add(int data)
{
	cout << "Adding " << data << endl;
	return addHelper(root, data);
}

bool AVL::addHelper(Node*& n, int value)
{
  // Case: n == NULL
  if(n == NULL)
  {
    Node* newNode = new Node(value);
    newNode->left = NULL; // Could be taken care of in Node constructor
    newNode->right = NULL; // Could be taken care of in Node constructor
    n = newNode;
    return true;
  }
  // Case: n->value == value
  else if(n->data == value)
  {
    return false;
  }
  // Case: value < n->value
  else if(value < n->data)
  {
    bool isAdded = addHelper(n->left, value);
    if(isAdded)
      rebalance(n);
    return isAdded;
  }
  // Case: value > n->value
  else if(value > n->data)
  {
    bool isAdded = addHelper(n->right, value);
    if(isAdded)
      rebalance(n);
    return isAdded;
  }
}

Node*& AVL::find(Node*& rootNode, int value)
{
	if (rootNode == NULL)
	{
		return rootNode;
	}
	else if (rootNode->getData() == value)
	{
		return rootNode;
	}
	else if (rootNode->getData() < value)
	{
		find(rootNode->right, value);
	}
	else if (rootNode->getData() > value)
	{
		find(rootNode->left, value);
	}
}

bool AVL::remove(int data)
{
	cout << "Removing " << data << endl;
	return removeHelper(root, data);
}

bool AVL::erase(Node*& rootNode, int data)
{

}
Node*& AVL::findRight(Node*& rootNode)
{
	if (rootNode->right == NULL)
	{
		return rootNode;
	}
	else
	{
		return findRight(rootNode->right);
	}
}
void AVL::clear()
{
	if (root != NULL)
	{
		root->erase();
	}
	delete root;
	root = NULL;
}

AVL::~AVL()
{
	clear();
	delete root;
}
AVL::AVL()
{
	root = NULL;
}
void AVL::rebalance(Node*& n)
{
  int balance = getBalance(n);
  if (balance == -2)
  {
    if (getBalance(n->left) == -1 || getBalance(n->left) == 0)
	{
		rotateRight(n);

	}
	else if (getBalance(n->left) == 1)
	{
		rotateLeft(n->left);
		rotateRight(n);
	}
	else
	{
		cout << "ERROR" << endl;
	}
  }
  else if (balance == 2)
  {
	  if (getBalance(n->right) == 1 || getBalance(n->right) == 0)
	  {
		  rotateLeft(n);
	  }
	  else if (getBalance(n->right) == -1)
	  {
		  rotateRight(n->right);
		  rotateLeft(n);
	  }
	  else
	  {
		  cout << "ERROR" << endl;
	  }
  }
}

int AVL::getBalance(Node*& n)
{
  int balance = 0;
  if (n == NULL)
  {
      return 0;
  }
  else if ((n->left != NULL) && (n->right != NULL))
  {
      balance = n->right->getHeight()  - n->left->getHeight();
  }
  else if ((n->left == NULL) && (n->right == NULL))
  {
      balance = 0;
  }
  else if (n->left == NULL)
  {
      balance = n->right->getHeight();
  }
  else if (n->right == NULL)
  {
      balance = 0 - n->left->getHeight();
  }
  return balance;
}

void AVL::rotateRight(Node*& n)
{
	if (n == NULL)
	{
		cout << "Error: Rotation around null node" << endl;
		return;
	}
	Node* k = n->left;
	if (k == NULL)
	{
		cout << "Error: rotation failed" << endl;
		return;
	}
	Node* temp = n;
	n = k;
	temp->left = k->right;
	k->right = temp;

}


void AVL::rotateLeft(Node*& n)
{
	if (n == NULL)
	{
		cout << "Error: Rotation around null node" << endl;
		return;
	}
	Node* k = n->right;
	Node* temp = n;
	if (temp == NULL || k == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	n = k;
	temp->right = k->left;
	k->left = temp;


}

bool AVL::removeHelper(Node*& n, int value)
{   
  // Case: n == NULL (I couldn't find the value, so return false)
  if (n == NULL)
  {
	  return false;
  }
  // Case: n->value == value (I found the node to delete)
  else if (n->data == value)
  {
	  if ((n->left == NULL) && (n->right == NULL))
	  {
		  //no kids
		  delete n;
		  n = NULL;
		  rebalance(n);
		  return true;
	  }
	  else if ((n->left != NULL) && (n->right == NULL))
	  {
		  //left kid
		  Node* temp = n->left;
		  delete n;
		  n = temp;
		  rebalance(n);
		  return true;
	  }
	  else if ((n->right != NULL) && (n->left == NULL))
	  {
		  //right kid
		  Node* temp = n->right;
		  delete n;
		  n = temp;
		  rebalance(n);
		  return true;
	  }
	  else
	  {
		  //both kids
		  Node*& localRoot = findRight(n->left);
		  n->data = localRoot->data;
		  removeHelper(n->left, localRoot->data);
		  rebalance(n);
		  return true;
	  }

  }
  else if (value < n->data)
  {
	bool isRemoved = removeHelper(n->left, value);
    if(isRemoved)
	{
		cout << "Remove calling rebalance on " << n->data << endl;
		rebalance(n);
	}
    return isRemoved;
  }
  else if (value > n->data)
  {
	bool isRemoved = removeHelper(n->right, value);
    if(isRemoved)
	{
		cout << "Remove calling rebalance on " << n->data << endl;
		rebalance(n);
	}
    return isRemoved;
  }

}