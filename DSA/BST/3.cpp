
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

Node* minBST(Node* root) {
	if (root == NULL)
		return NULL;

	Node* temp = root;
	while (temp -> left != NULL) {
		temp = temp -> left;
	}
	return temp;
}


Node* deleteFromBST(Node* root, int val) {
	if (root == NULL)
		return NULL;
	if (root->data == val) {
		// 0 child
		if (root -> left == NULL && root -> right == NULL) {
			delete root;
			return NULL;
		}

		// 1 Child
		if (root->left !=  NULL && root->right == NULL) {
			Node* temp = root -> left;
			delete root;
			return temp;
		}
		if (root -> left == NULL && root->right != NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// 2 Child
		if (root -> left != NULL && root->right != NULL) {
			int mini = minBST(root->right) -> data;
			root -> data = mini;
			root -> right = deleteFromBST(root->right, mini);
			return root;
		}
	} else if (root->data < val) {
		// Go to right part of BST
		root -> right = deleteFromBST(root->right, val);
		return root;
	} else {
		// Go to left part of BST
		root -> left = deleteFromBST(root->left, val);
		return root;
	}
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


int main()
{
	// 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	takeInput(root);
	cout << "\nLevel Order Traversal: ";
	levelOrderTraversal(root);

	int val;
	// cout << "\nEnter a value to delete from BST: ";
	// cin >> val;
	root  = deleteFromBST(root, 8);
	cout << "\nLevel order after Deletion: ";
	levelOrderTraversal(root);

	root  = deleteFromBST(root, 7);
	cout << "\nLevel order after Deletion: ";
	levelOrderTraversal(root);

	root  = deleteFromBST(root, 10);
	cout << "\nLevel order after Deletion: ";
	levelOrderTraversal(root);
	return 0;
}