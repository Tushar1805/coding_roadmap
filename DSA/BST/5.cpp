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

int solve(Node* root, int &i, int k) {
	if (root == NULL)
		return -1;
	// L
	int left = solve(root->left, i, k);
	if (left != -1) {
		return left;
	}
	// N
	i++;
	if (i == k)
		return root -> data;
	// R
	return solve(root->right, i, k);
}


int main()
{
	// 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	takeInput(root);
	cout << "\nLevel Order Traversal: ";
	levelOrderTraversal(root);
	int k;
	cout << "\nEnter the value of k: ";
	cin >> k;
	int i = 0;
	int ans = solve(root, i, k);
	cout << "\n" << k << " th smallest value in BST is " << ans;
	return 0;
}