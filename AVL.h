#pragma once
#include "AVLInterface.h"
#include "Node.h"
using namespace std;

class AVL : AVLInterface
{
    public:
        virtual NodeInterface * getRootNode() const;
        virtual bool add(int data);
	    virtual bool remove(int data);
	    virtual void clear();
        AVL();
        ~AVL();
    protected:
	    Node*& find(Node*& rootNode, int value);
	    bool erase(Node*& rootNode, int data);
	    Node*& findRight(Node*& rootNode);
        bool addHelper(Node*& n, int value);
        bool removeHelper(Node*& n, int value);
        void rebalance(Node*& n);
        int getBalance(Node*& n);
        void rotateRight(Node*& n);
        void rotateLeft(Node*& n);
    private:
	    Node* root;
	    int maxHeight;
 
};