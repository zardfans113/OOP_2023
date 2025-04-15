#include "BST.h"
#include<iostream>
#include<queue>
using namespace std;

void BST::insert(Node* insertNode) {
       // empty -> set root
        if (root == NULL) {
            root = insertNode;
            return;
        }

        Node* currentNode = root;
        Node* parentNode = NULL;
        while (currentNode != NULL) {
            parentNode = currentNode;

            if (insertNode->getValue() < currentNode->getValue()) {
                currentNode = currentNode->getLchild();
            }
            else {
                currentNode = currentNode->getRchild();
            }
        }
        if (insertNode->getValue() < parentNode->getValue()) {
            parentNode->setLchild(insertNode);
        }
        else {
            parentNode->setRchild(insertNode);
        }
  
       
	//TODO: insert a node to BST
}

void BST::InOrder_traversal(Node* root)
{
    if (root == NULL) return;
    InOrder_traversal(root->getLchild());
    cout << root->getValue() << " ";
    InOrder_traversal(root->getRchild());
	//TODO: Inorder traversal
}

void BST::PreOrder_traversal(Node* root)
{
    if (root == NULL) return;
    cout << root->getValue() << " ";
    PreOrder_traversal(root->getLchild());
    PreOrder_traversal(root->getRchild());
	//TODO: Preorder traversal
}

void BST::PostOrder_traversal(Node* root)
{
    if (root == NULL) return;
    PostOrder_traversal(root->getLchild());
    PostOrder_traversal(root->getRchild());
    cout << root->getValue() << " ";
	//TODO: Postorder traversal

}

Node* BST::getRoot() {
    return root;
	//TODO: return root of BST
}