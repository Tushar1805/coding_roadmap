#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* buildTree(Node* root) {
	int data;
	cout << "Enter Node data: ";
	cin >> data;
	if (data == -1)
		return NULL;
	root = new Node(data);
	cout << "Enter the left of Node " << data << endl;
	root->left = buildTree(root -> left);
	cout << "Enter the right of Node " << data << endl;
	root -> right = buildTree(root -> right);
	return root;
}

void inoderTraversal(Node* root) {
	if (root == NULL)
		return;

	inoderTraversal(root -> left);
	cout << root -> data << " ";
	inoderTraversal(root -> right);
}

vector<int> inoderIterative(Node* root) {
	vector<int> ans;
	if (root == NULL)
		return ans;
	stack<Node*> s;
	Node* node = root;
	while (true) {
		if (node != NULL) {
			s.push(node);
			node = node -> left;
		} else {
			if (s.empty()) break;
			node = s.top();
			s.pop();
			ans.push_back(node -> data);
			node = node -> right;
		}

	}
	return ans;
}

void preoderTraversal(Node* root) {
	if (root == NULL)
		return;

	cout << root -> data << " ";
	preoderTraversal(root->left);
	preoderTraversal(root->right);
}

vector<int> preOrderIterative(Node* root) {
	vector<int> ans;
	if (root == NULL)
		return ans;
	stack<Node*> s;
	Node* node = root;

	while (true) {
		if (node != NULL) {
			s.push(node);
			ans.push_back(node->data);
			node = node -> left;
		} else {
			if (s.empty()) break;
			node = s.top();
			s.pop();
			node = node -> right;
		}
	}
	return ans;
}

void postorderTraversal(Node* root) {
	if (root == NULL)
		return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}

vector<int> postorderIterative(Node* root) {
	vector<int> ans;
	if (root == NULL)
		return ans;
	stack<Node*> s;
	Node* node = root;
	Node* temp = NULL;

	while (!s.empty() || node != NULL) {
		if (node != NULL) {
			s.push(node);
			node = node -> left;
		} else {
			Node* temp = s.top() -> right;
			if (temp == NULL) {
				temp = s.top();
				s.pop();
				ans.push_back(temp->data);
				while (!s.empty() && temp == s.top()->right) {
					temp = s.top();
					s.pop();
					ans.push_back(temp->data);
				}
			} else {
				node = temp;
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	Node* root = NULL;
	root = buildTree(root);
	cout << "\nInorder Traversal: ";
	inoderTraversal(root);
	cout << "\nPreorder Traversal: ";
	preoderTraversal(root);
	cout << "\nPostorder Traversal: ";
	postorderTraversal(root);
	return 0;
}