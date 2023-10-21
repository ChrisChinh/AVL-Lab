#pragma once
#include "BSTInterface.h"
#include "Node.h"
using namespace std;

class BST : BSTInterface
{
	private:
		Node* root;
		int size;
	protected:
		Node*& find(Node*& rootNode, int value);
		bool erase(Node*& rootNode, int data);
		Node*& findRight(Node*& rootNode);
	public:
		NodeInterface* getRootNode() const;
		bool add(int data);
		bool remove(int data);
		void clear();
		BST();
		~BST();
};