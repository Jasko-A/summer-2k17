#include "Binarysearch.h"

#include <iostream>
#include <string>

using namespace std;

BST::BST()
{
	root = NULL;
}

void BST::insertNode(string name, float p)
{
	Node * newNode = new Node;
	Node * parent;
	newNode->food = name;
	newNode->price = p;
	newNode->left = NULL;
	newNode->right = NULL;
	parent = NULL;

	if (root == NULL) 
		root = newNode;

	else 
	{
		Node * leaf;
		leaf = root;
		while (leaf) 
		{
			parent = leaf;
			if (newNode->food > leaf->food)
				leaf = leaf->right;
			else
				leaf = leaf->left;
		}
		if (newNode->food < parent->food)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
}

float BST::getPrice(string name, Node * curr)
{

	if (curr->food == name)
	{
		return curr->price;
	}
	else if (name > curr->food)
	{
		curr = curr->right;
		getPrice(name, curr);
	}
	else if (name < curr->food)
	{
		curr = curr->left;
		getPrice(name, curr); 
	}

}
