//! Kth Ancestor in a Tree

// Given a binary tree of size  N, a node, and a positive integer k.,
// Your task is to complete the function kthAncestor(), the function
// should return the kth ancestor of the given node in the binary tree.
// If there does not exist any such ancestor then return -1.
// Note: It is guaranteed that the node exists in the tree.

// Example 1:

// Input:
// K = 2 Node = 4
// Output: 1
// Explanation:
// Since, K is 2 and node is 4, so we
// first need to locate the node and
// look k times its ancestors.
// Here in this Case node 4 has 1 as his
// 2nd Ancestor aka the Root of the tree.
// Example 2:

// Input:
// k=1
// node=3
//       1
//     /   \
//     2     3

// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.
// Your Task:
// You are asked to complete the function kthAncestor()
// which accepts root of the tree, k and node as input parameters,
// and returns the kth ancestor of Node which contains node as its value.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<=N<=105
// 1<= K <= 100
// 1 <= Node.data <= N

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node* buildTree(Node* root) {
	int data;
	cout << "Enter Node data: ";
	cin >> data;
	if (data == -1)
		return NULL;
	root =  newNode(data);
	cout << "Enter the left of Node " << data << endl;
	root->left = buildTree(root -> left);
	cout << "Enter the right of Node " << data << endl;
	root -> right = buildTree(root -> right);
	return root;
}

int len = 0;
void lengthTree(Node* root) {
	if (root == NULL) return;
	lengthTree(root->left);
	len++;
	lengthTree(root->right);
}

void fillParent(Node* &root, vector<int> &parent) {
	queue<Node*> q;
	q.push(root);
	parent[root->data] = -1;

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp -> left) {
			parent[temp->left->data] = temp -> data;
			q.push(temp->left);
		}
		if (temp -> right) {
			parent[temp->right->data] = temp -> data;
			q.push(temp->right);
		}
	}
}
int kthAncestor(Node *root, int k, int node)
{
	// Code here
	if (root == NULL)
		return -1;
	int ans;
	int count = 0;
	lengthTree(root);
	vector<int> parent(len + 1, -1);
	fillParent(root, parent);
	while (node != -1) {
		node = parent[node];
		count++;
		if (count == k)
			return node;
	}
	return -1;
}

int main()
{

	int k , node;
	cout << "Enter the kth ancestor value: ";
	cin >> k;
	cout << "Enter the node of which the ancestor has to be find: ";
	cin >> node;
	Node* root = NULL;
	root =  buildTree(root);
	cout << endl << k << "th ancestor of " << node << " is: " << kthAncestor(root, k, node) << endl;

	return 0;
}