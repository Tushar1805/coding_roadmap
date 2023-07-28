#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		this -> data = d;
		this -> left = NULL;
		this -> right = NULL;
	}
};

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp -> left) {
			q.push(temp->left);
		}
		if (temp -> right) {
			q.push(temp->right);
		}
	}
}

Node* insertIntoBST(Node* root, int d) {
	if (root == NULL) {
		root = new Node(d);
		return root;
	}

	if (root->data < d) {
		root -> right = insertIntoBST(root->right, d);
	} else {
		root -> left = insertIntoBST(root -> left, d);
	}
	return root;
}

void takeInput(Node* &root) {
	int data;
	// cout << "Enter data: ";
	cin >> data;
	while (data != -1) {
		root = insertIntoBST(root, data);
		// cout << "Enter data: ";
		cin >> data;
	}
}

int minBST(Node* root) {
	if (root == NULL)
		return -1;

	Node* temp = root;
	while (temp -> left != NULL) {
		temp = temp -> left;
	}
	return temp->data;
}

int maxBST(Node* root) {
	if (root == NULL)
		return -1;

	Node* temp = root;
	while (temp -> right != NULL) {
		temp = temp -> right;
	}
	return temp->data;
}

int main()
{
	// 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	takeInput(root);
	cout << "\nLevel Order Traversal: ";
	levelOrderTraversal(root);

	cout << "\nMinimum value in the BST is: " << minBST(root);
	cout << "\nMaximum value in the BST is: " << maxBST(ro ot);
	return 0;
}