#include "Node.h"
#include <cstddef>
using namespace std;

Node::~Node()
{
}
int Node::getData() const
{
	return data;
}
Node* Node::getLeftChild() const
{
	return this->left;
}
Node* Node::getRightChild() const
{
	return this->right;
}
Node::Node(int value)
{
	left = NULL;
	right = NULL;
	data = value;
}
void Node::erase()
{
	if (left != NULL)
	{
		left->erase(); 
		delete left;
	}
	if (right != NULL)
	{
		right->erase();
		delete right;
	}
}
int Node::getHeight()
{
	int height = findHeight(this);
	return height;
}
int Node::findHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return findMax(findHeight(root->left), findHeight(root->right)) + 1;
	
}
int Node::findMax(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}