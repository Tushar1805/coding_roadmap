//! Left View of Binary Tree

// Given a Binary Tree, return Left view of it.
// Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
// The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    / \
//   4     5   6    7
//    \
//      8

// Example 1:

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3

// Example 2:

// Input:

// Output: 10 20 40
// Your Task:
// You just have to complete the function leftView()
// that returns an array containing the nodes that are in the left view.
// The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 0 <= Number of nodes <= 100
// 1 <= Data of a node <= 1000

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Should return  right view of tree
class Solution
{

private:

	int max_level;

	void leftV(vector<int> &a, Node* root, int level) {
		if (root == NULL)
			return;
		if (max_level < level) {
			a.push_back(root->data);
			max_level = level;
		}
		leftV(a, root->left, level + 1);
		leftV(a, root->right, level + 1);

	}

public:
	//Function to return list containing elements of left view of binary tree.
	vector<int> leftView(Node *root)
	{
		// Your code here
		vector<int> ans;
		max_level = 0;
		if (root == NULL)
			return ans;

		leftV(ans, root, 1);
		return ans;
	}
};


Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


int main() {

	string s;
	cout << "Enter elements of binary tree: ";
	getline(cin, s);
	Node* root = buildTree(s);

	Solution ob;
	vector<int> vec = ob.leftView(root);
	for (int x : vec) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}