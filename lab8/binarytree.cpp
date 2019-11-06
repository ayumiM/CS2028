// lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<class T>
class BinaryTree {
public:
	struct TreeNode {
		T value;
		TreeNode* left;
		TreeNode* right;

	};

	TreeNode* root;
	void insert(TreeNode*&, TreeNode*&); 
	void destroySubTree(TreeNode*); 
	void deleteNode(T, TreeNode*&); 
	void makeDeletion(TreeNode*&); 
	void displayInOrder(TreeNode*); 
	void displayPreOrder(TreeNode*); 
	void displayPostOrder(TreeNode*);
public:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {
		destroySubTree(root);
	}
	void insertNode(T);
	bool searchNode(T);
	void remove(T);
	void displayInOrder() {
		outputTree(root, 0);
	}
	void displayPreOrder() {
		displayPreOrder(root);
	}
	void displayPostOrder() {
		displayPostOrder(root);
	}

	void outputTree(TreeNode*, int);


};

template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
	if (nodePtr == nullptr) {// Insert the node.
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value){
		insert(nodePtr->left, newNode);
	}// Search the left branch
	else{
		insert(nodePtr->right, newNode);// Search the right branch
	}

}

template <class T>void BinaryTree<T>::insertNode(T num) {
	TreeNode* newNode = nullptr;// Pointer to a new node.
	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;
	// Insert the node.
	insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode* nodePtr) { 
	if (nodePtr->left) { 
		destroySubTree(nodePtr->left); 
	}
	if (nodePtr->right) { 
		destroySubTree(nodePtr->right); 
	}
	delete nodePtr; 
}

template <class T>
bool BinaryTree<T>::searchNode(T num) { 
	bool status = false; 
	TreeNode* nodePtr = root; 
	while (nodePtr) { 
		if (nodePtr->value == num) { 
			status = true; 
		} 
		else if (num < nodePtr->value) { 
			nodePtr = nodePtr->left; 
		} 
		else { 
			nodePtr = nodePtr->right; 
		} 
	}return status; 
}

template <class T>
void BinaryTree<T>::remove(T num) { 
	deleteNode(num, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode*& nodePtr) {
	if (num < nodePtr->value) { 
		deleteNode(num, nodePtr->left); 
	}
	else if (num > nodePtr->value) { 
		deleteNode(num, nodePtr->right); 
	}
	else { 
		makeDeletion(nodePtr);
	}
}

template<class T>
void BinaryTree<T>::makeDeletion(TreeNode*& nodePtr) {
	TreeNode* tempNodePtr = nullptr;
	if (nodePtr == nullptr) { 
		cout << "Cannot delete empty node.\n"; 
	}
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr; 
		nodePtr = nodePtr->left; // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr){
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child
		delete tempNodePtr;
	}
	else {
		// Move one node the right.
		tempNodePtr = nodePtr->right;// Go to the end left node.
		while (tempNodePtr->left){
			tempNodePtr = tempNodePtr->left;
		}// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) { 
	if (nodePtr) { 
		displayInOrder(nodePtr->left); 
		cout << nodePtr->value << endl; 
		displayInOrder(nodePtr->right); 
	} 

}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) { 
	if (nodePtr) { 
		cout << nodePtr->value << endl; 
		displayPreOrder(nodePtr->left);     
		displayPreOrder(nodePtr->right); 
	} 
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) { 
	if (nodePtr) { 
		displayPostOrder(nodePtr->left);   
		displayPostOrder(nodePtr->right); 
		cout << nodePtr->value << endl; 
	} 
}

template<class T>
void BinaryTree<T>::outputTree(TreeNode* nodePtr, int TotalSpaces) {
	//int count = 0;
	while (nodePtr) {
		outputTree(nodePtr->right, TotalSpaces + 5);
		for (int i = 1; i < TotalSpaces; i++) {
			cout << " ";
		}
		//cout << endl;
		cout << nodePtr->value;
		cout << endl;
		nodePtr = nodePtr->left;
		TotalSpaces = TotalSpaces + 5;
	}
}


int main()
{
	BinaryTree<int> tree;
	int TotalSpaces = 0;
	//cout << "Inserting nodes\n";
	tree.insertNode(49);
	tree.insertNode(28);
	tree.insertNode(83);
	tree.insertNode(18);
	tree.insertNode(40);
	tree.insertNode(71);
	tree.insertNode(97);
	tree.insertNode(11);
	tree.insertNode(19);
	tree.insertNode(32);
	tree.insertNode(44);
	tree.insertNode(69);
	tree.insertNode(72);
	tree.insertNode(92);

	tree.insertNode(99);

	tree.displayInOrder();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
