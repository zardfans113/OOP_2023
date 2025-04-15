#pragma once
#include <iostream>
#include "Node.h"
class BST {
public:
	BST() {
		root = NULL;
	}
	void insert(Node* node);
	void InOrder_traversal(Node* root);
	void PreOrder_traversal(Node* root);
	void PostOrder_traversal(Node* root);
	Node* getRoot();
private:
	Node* root;
};
