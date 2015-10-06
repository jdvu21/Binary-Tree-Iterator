#include "binarytree.h"
#include <iostream>

using namespace std;

void BinaryTree::insertNode(int num)
{
	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

bool BinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

void BinaryTree::displayHiToLow(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayHiToLow(nodePtr->right);
		cout << nodePtr->value << " ";
		displayHiToLow(nodePtr->left);
	}
}

void BinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr;

	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

int BinaryTree::depth(int num, int level)
{
    TreeNode *nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == num)
		{
                return level;
		}
		else
        {   if (num < nodePtr->value)
            {
                level++;
                nodePtr = nodePtr->left;
            }
            else
            {
                level++;
                nodePtr = nodePtr->right;
            }
        }
	}
    return -1;
}

int BinaryTree::maxSumPath (TreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left==NULL && root->right==NULL)
		return root->value;
	return max(root->value+maxSumPath(root->left),root->value+maxSumPath(root->right));
}

int BinaryTree::findMax()
{
	TreeNode *nodePtr = root;
        //cout << "\nFinding max sum..." << endl;
	return maxSumPath(nodePtr);
	//cout << "done." << endl;
}

int BinaryTree::height(TreeNode *root)
{
	if (root == NULL)
	{return -1;}
	int lefth = height(root->left);
	int righth = height(root->right);

	if (lefth > righth)
		return lefth + 1;
	else
		return righth + 1;
}

bool BinaryTree::isBalanced(int leftTree, int rightTree)
{
	if (leftTree == rightTree || leftTree + 1 == rightTree || rightTree + 1 == leftTree || leftTree - 1 == rightTree || rightTree - 1 == leftTree)
		{
			cout << "Tree is balanced!" << endl;
			return true;
		}
	else
	{
		cout << "Tree is not balanced!" << endl;
		return false;
	}
}
