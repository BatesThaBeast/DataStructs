#pragma once
#ifndef AVLTREE
#define AVLTREE
#include "BinaryTree.h"
template <class T>
class AVLTree :
	public BinaryTree <T>
{
private:
	struct AVLNode : BinaryTree<T>::Node 
	{
		int height = 0,count = 0;
	};
public:
	void AVLInsert(const T& data) { this->AVLInsert(data, this->Root); }
	void AVLRemove(const T& data) { this->AVLRemove(data, this->Root); }
	void AVLprintTree() { this->AVLprintTree(this->Root); }
private:
	void AVLInsert(const T& data, AVLNode* root)
	{
		if (root == NULL)
		{
			root = new AVLNode(data, NULL, NULL);
			root->count++;
		}
		else if (data < root->Data)
		{
			insert(data, root->Left);
			if (height(root->Left) - height(root->Right) == 2) { rotateLeft(root); }
			else { doubleRotateLeft(root); }
		}
		else if (data > root->Data)
		{
			insert(data, root->Right);
			if (height(root->Right) - height(root->Left) == 2) { rotateRight(root); }
			else { doubleRotateRotate(root); }
		}
		root->height = max(height(root->Left), height(root->Right)) + 1;
	}
	void AVLRemove(const T& data, AVLNode*& root)
	{
		if (root == NULL)
			return;
		// data searched is smaller go down the left sub-tree
		else if (data < root->element)
		{
			remove(data, root->Left);
			if (height(root->Right) - height(root->Left) > 1)
			{
				if (height(root->Right->Right) >= height(root->Right->Left))
					rotateRight(root);
				else
					doubleRotateRight(root);
			}
		}
		//data being searched is larger go down the right sub-tree

		else if (data > root->element)
		{
			remove(data, root->Right);
			if (height(root->Left) - height(root->Right) > 1)
			{
				if (height(root->Left->Left) >= height(root->Left->Right))
					rotateLeft(root);
				else
					doubleRotateLeft(root);
			}
		}
		else //Key is the same as the root's key. It needs to be removed
		{
			//Node with one or no children
			if (root->Left == NULL | root->Right == NULL)
			{
				AVLNode* temp = root->Left ? root->Left : root->Right;
				//Case has no children
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else //has one child
				{
					*root = *temp;
				}
				delete temp;
			}
			else
			{
				AVLNode* temp = findMin(root->Right);
				root->Data = temp->Data;
				remove(temp->Data, root->Right);
			}
			if (root != NULL)
				root->height = max(height(root->Left), height(root->Right)) + 1;
		}
	}
	int height(AVLNode* root) { return root == NULL ? -1 : root->height; }
	int max(int lhs, int rhs) { return lhs > rhs ? lhs : rhs; }
	void rotateRight(AVLNode*& node)
	{
		AVLNode* p;

		p = node->left;
		node->left = p->right;
		p->right = node;
		node->height = max(height(node->Left), height(node->Right)) + 1;
		p->height = max(height(p->Right), node->height) + 1;
		node = p;
	}
	void rotateLeft(AVLNode*& node)
	{
		AVLNode* p;

		p = node->right;
		node->right = p->left;
		p->left = node;
		node->height = max(height(node->Left), height(node->Right)) + 1;
		p->height = max(height(p->Left), node->height) + 1;
		node = p;
	}
	void doubleRotateRight(AVLNode*& node)
	{
		rotateRight(node->Left);
		rotateLeft(node);
	}
	void doubleRotateLeft(AVLNode*& node)
	{
		rotateLeft(node->Right);
		rotateRight(node);
	}
	void AVLprintTree(AVLNode*& n)
	{
		if (n != NULL)//check to see if end of tree has been reached
		{
			cout << n->Data << " - " << n->count << endl;//prints AVLNode's current data
			this->printTree(n->Left);//traverses using recursion down-left of tree then prints
			this->printTree(n->Right);//traverses using recursion down-right of tree then prints
		}
	}
};
#endif
