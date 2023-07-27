#include<bits/stdc++.h>
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

bool checkForBST(Node* root, int min, int max) {
	if (root == NULL)
		return true;
	if (root->data >= min && root->data <= max) {
		bool left = checkForBST(root->left, min, root->data);
		bool right = checkForBST(root ->right, root->data, max);
		return left && right;
	} else {
		return false;
	}
}


int main()
{
	// 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	takeInput(root);
	cout << "\nLevel Order Traversal: ";
	levelOrderTraversal(root);
	bool check = checkForBST(root, INT_MIN, INT_MAX);
	check ? cout << "\nThe given tree is BST" : cout << "\nNot BST";
	return 0;
}