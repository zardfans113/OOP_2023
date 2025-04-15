#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"

using namespace std;

int main() {
	/*  Do not modify the content in "int main ()". */

	fstream file;
	file.open("input1.txt");

	if (!file.is_open()) {
		cout << "Fail to open file" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;

	while (TestCase) {
		BST bst;

		int NumberOfNode;
		file >> NumberOfNode;

		for (int i = 0; i < NumberOfNode; i++) {
			int NodeValue;
			file >> NodeValue;
			bst.insert(new Node(NodeValue));
		}

		//Inorder traversal
		cout << "Inorder_traversal: ";
		bst.InOrder_traversal(bst.getRoot());
		cout << endl;

		//Preorder traversal
		cout << "Preorder_traversal: ";
		bst.PreOrder_traversal(bst.getRoot());
		cout << endl;

		//Postorder traversal
		cout << "Postorder_traversal: ";
		bst.PostOrder_traversal(bst.getRoot());
		cout << endl;

		cout << endl;
		TestCase--;
	}


	system("pause");
	return 0;

}