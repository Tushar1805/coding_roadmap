//! Kth largest element in the BST

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

void inorder(Node* root, vector<int> & ans) {
	// Base case
	if (root == NULL) return;

	inorder(root ->left, ans);
	ans.push_back(root ->data);
	inorder(root -> right, ans);
}

Node* insertNode(int data, Node* root) {
	if (root == NULL) {
		Node* newNode = new Node(data);
		root = newNode;
	} else {
		if (data <= root -> data) {
			root -> left = insertNode(data, root -> left);
		} else {
			root -> right = insertNode(data, root -> right);
		}
	}
	return root;
}


void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);

	// Uncomment this to print the tree like structure
	// q.push(NULL);

	while (!q.empty()) {
		//! To print in the tree like structure

		// Node* temp = q.front();
		// q.pop();
		// if (temp == NULL) {
		// 	// old level has been traversed completely
		// 	cout << endl;
		// 	if (!q.empty()) {
		// 		// queue still has some child nodes
		// 		q.push(NULL);
		// 	}
		// } else {
		// 	cout << temp -> data << " ";
		// 	if (temp -> left) q.push(temp -> left);
		// 	if (temp -> right) q.push(temp -> right);
		// }

		Node* temp = q.front();
		q.pop();

		cout << temp -> data << " ";
		if (temp -> left) q.push(temp -> left);
		if (temp -> right) q.push(temp -> right);
	}
}

int main() {
	Node* root = NULL;
	while (true) {
		int data;
		cout << "Enter the node of tree or -1 to exit: ";
		cin >> data;
		if (data == -1) break;
		root = insertNode(data, root);
	}
	cout << "Level order Traversal: ";
	levelOrderTraversal(root);

	vector<int> ans;
	int k;
	inorder(root, ans);
	cout << "Enter the kth element to find in the BST: ";
	cin >> k;
	cout << "Kth largest element of BST: " << ans[ans.size() - k];
	return 0;
}

