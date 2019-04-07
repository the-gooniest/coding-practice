#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d): data(d) {}
};

void printNodesOnLevel(Node* root, int level, int curLevel = 0) {
	if (root == NULL) return;
	if (level == curLevel) cout << root->data << " ";
	if (curLevel >= level) return;
	printNodesOnLevel(root->left, level, curLevel + 1);
	printNodesOnLevel(root->right, level, curLevel + 1);
}

// Time complexity: O(n), n = # nodes in the tree
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	printNodesOnLevel(root, 2);
}