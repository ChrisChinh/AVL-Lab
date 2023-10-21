#include "BST.h"
#include <iostream>
using namespace std;

NodeInterface* BST::getRootNode() const
{
	return root;
}
bool BST::add(int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		size++;
		return true;
	}
	else
	{
		Node*& toAdd = find(root, data);
		if (toAdd == NULL)
		{
			toAdd = new Node(data);
			size++;
			return true;
		}
		else
		{
			return false;
		};
	}

}
Node*& BST::find(Node*& rootNode, int value)
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

bool BST::remove(int data)
{
	return erase(root,data);
}

bool BST::erase(Node*& rootNode, int data)
{
	if (rootNode == NULL)
	{
		return false;
	}
	else if (data < rootNode->data)
	{
		erase(rootNode->left,data);
	}
	else if (data > rootNode->data)
	{
		erase(rootNode->right, data);
	}
	else
	{
		if (rootNode->left == NULL && rootNode->right == NULL)
		{
			delete rootNode;
			rootNode = NULL;
			return true;
		}
		else if (!(rootNode-> left != NULL) != !(rootNode->right != NULL))
		{
			if (rootNode->left != NULL)
			{
				Node* tempPointer = rootNode->left;
				delete rootNode;
				rootNode = tempPointer;
				size--;
				return true;
			}
			else if (rootNode->right != NULL)
			{
				Node* tempPointer = rootNode->right;
				delete rootNode;
				rootNode = tempPointer;
				size--;
				return true;
			}
		}
		else
		{
			Node*& local_root = findRight(rootNode->left);
			rootNode->data = local_root->data;
			erase(rootNode->left,local_root->data);
		}
	}

}
Node*& BST::findRight(Node*& rootNode)
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
void BST::clear()
{
	if (root != NULL)
	{
		root->erase();
	}
	delete root;
	root = NULL;
	size = 0;
}

BST::~BST()
{
	clear();
	delete root;
}
BST::BST()
{
	size = 0;
	root = NULL;
}