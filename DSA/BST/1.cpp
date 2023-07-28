#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		this-> data = d;
		this -> left = NULL;
		this -> right = NULL;
	}
};

Node* insertIntoBST(Node* root, int d) {
	if (root == NULL) {
		root = new Node(d);
		return root;
	}

	if (d < root->data) {
		root->left = insertIntoBST(root -> left, d);
	} else {
		root->right = insertIntoBST(root->right, d);
	}
	return root;
}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			// Old level has been traversed completely
			cout << endl;
			if (!q.empty()) {
				// Queue still has some child nodes
				q.push(NULL);
			}
		} else {
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}

	}
}

void inoderTraversal(Node* root) {
	if (root == NULL)
		return;

	inoderTraversal(root -> left);
	cout << root -> data << " ";
	inoderTraversal(root -> right);
}

void takeInput(Node* &root) {
	int data;
	cin >> data;
	while (data != -1) {
		root = insertIntoBST(root, data);
		cin >> data;
	}
}

int main(int argc, char const *argv[])
{

	// 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	takeInput(root);
	cout << "Printing the BST: " << endl;
	levelOrderTraversal(root);
	cout << "\nInorder Traversal of BST: ";
	inoderTraversal(root);

	return 0;
}