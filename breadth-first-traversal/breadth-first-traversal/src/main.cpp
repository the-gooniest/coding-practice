#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d) {}
};

queue<Node*> nodes;
void breadthFirstTraversal(Node* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	nodes.push(root->left);
	nodes.push(root->right);
	if (nodes.size() == 0) return;
	Node* nextNode = nodes.front();
	nodes.pop();
	breadthFirstTraversal(nextNode);
}

// Time complexity: O(n), n = # of tree nodes
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	breadthFirstTraversal(root);
}