#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int data;
	Node(int d) : data(d), next(nullptr) {}
};

Node* reverseLinkedList(Node* root) {
	Node* current = root;
	Node* prev = nullptr;
	Node* next = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main() {
	Node* root = new Node(0);
	Node* temp = root;
	for (int i = 1; i < 100; ++i) {
		temp->next = new Node(i);
		temp = temp->next;
	}

	root = reverseLinkedList(root);
	
	temp = root;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}