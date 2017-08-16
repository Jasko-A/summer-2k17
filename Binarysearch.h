#pragma once
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <string>

using namespace std;

class BST {
private:
	struct Node {
		string food;
		float price;
		Node * left; //store address of left child
		Node * right; //store address of right child
	};
	Node * root; //stores address of the root Node of the binary tree
public:
	BST();
	void insertNode(string, float);

};


#endif // !BINARYSEARCH_H