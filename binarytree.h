// page 1141

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;
#include <iostream>

class BinaryTree
{
private:
	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&); // required function #3 done. tested.
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const; // required function #4 done. tested.
	void displayPostOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayHiToLow(TreeNode *) const;

public:
	BinaryTree()
	{
		root = NULL;
	}

	~BinaryTree()
	{
		destroySubTree(root);
	}

	void remove(int num)
	{deleteNode(num, root);}

	void displayInOrder() const
	{displayInOrder(root);}

    void displayPreOrder() const
    {displayPreOrder(root);}

    void displayPostOrder() const
    {displayPostOrder(root);}

    void displayHiToLow() const
    {displayHiToLow(root);}

    void balanceCheck()
    {
    	isBalanced(height(root->left), height(root->right));
    }
	void insertNode(int); // required function #2 done. tested.
	bool searchNode(int); // required function #1 done. tested.
    int depth(int, int); // required function #5 done. tested.
	int findMax(); // required function #6 done. tested.
	bool isBalanced(int, int); // required function #7 done.tested.
    int maxSumPath(TreeNode *);
    int height(TreeNode *);
};

#endif
