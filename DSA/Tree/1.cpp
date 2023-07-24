#include <iostream>
#include <queue>
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

Node* buildTree(Node* root) {

	int data;
	cout << "Enter Node data: ";
	cin >> data;
	root = new Node(data);

	if (data == -1)
		return NULL;
	cout << "Enter the Left of Node " << data << endl;
	root->left = buildTree(root->left);
	cout << "Enter the Right of Node " << data << endl;
	root->right = buildTree(root->right);
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

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	// Creating Tree
	root = buildTree(root);

	// Level Order Traversal / BFS
	cout << "\n\nRepresentation of binary tree\n";
	levelOrderTraversal(root);
	return 0;
}