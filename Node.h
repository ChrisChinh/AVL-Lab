#pragma once
#include "NodeInterface.h"
using namespace std;

class Node : NodeInterface
{
	public:
	~Node();
	Node(int value);
	int getData() const;
	Node* getLeftChild() const;
	Node* getRightChild() const;
	int getHeight();
	int findHeight(Node* root);
	int findMax(int a, int b);
	protected:
	Node* left;
	Node* right;
	void erase();
	int data;
	friend class AVL;
	friend class BST;
};