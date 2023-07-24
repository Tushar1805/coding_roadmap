#include <iostream>
#include <queue>
#include <stack>
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

void reverseLevelOrderTraversal(Node* root) {
	stack<int> s;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			// Old level has been traversed completely
			s.push(-1);
			if (!q.empty()) {
				// Queue still has some child nodes
				q.push(NULL);
			}
		} else {
			s.push(temp -> data);
			if (temp->right) {
				q.push(temp->right);
			}
			if (temp->left) {
				q.push(temp->left);
			}
		}

	}

	while (!s.empty()) {

		if (s.top() == -1) {
			cout << endl;
			s.pop();
		}

		cout << s.top() << " ";
		s.pop();
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
	reverseLevelOrderTraversal(root);
	return 0;
}