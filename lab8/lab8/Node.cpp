#include "Node.h"
int Node::getValue() {
	return value;
	// TODO: return the value of node
}

Node* Node::getLchild() {
	return lchild;
	// TODO: return the left child of this node
}
Node* Node::getRchild() {
	return rchild;
	// TODO: return the right child of this node
}

void Node::setLchild(Node* node) {
	lchild = node;
	// TODO: set the left child of this node
}
void Node::setRchild(Node* node) {
	rchild = node;
	// TODO: set the right child of this node
}