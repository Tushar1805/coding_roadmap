//! Level order traversal in spiral form

// Given a binary tree and the task is to find the spiral order traversal of the tree.

// Spiral order Traversal mean: Starting from level 0 for root node,
// for all the even levels we print the node's value from right to left and
// 	for all the odd levels we print the node's value from left to right.

// For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2:

// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40
// Your Task:
// The task is to complete the function findSpiral()
// which takes root node as input parameter and returns the elements
// in spiral form of level order traversal as a list.
// The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105
// 0 <= Data of a node <= 105

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
public:
	vector<int> findSpiral(Node *root)
	{
		vector<int> ans;
		if (root == NULL)
			return ans;
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(root);

		while (!s1.empty() || !s2.empty()) {
			while (!s1.empty()) {
				Node* temp = s1.top();
				ans.push_back(temp->data);
				s1.pop();
				if (temp-> right) s2.push(temp->right);
				if (temp -> left) s2.push(temp -> left);
			}

			while (!s2.empty()) {
				Node* temp = s2.top();
				ans.push_back(temp->data);
				s2.pop();
				if (temp -> left) s1.push(temp -> left);
				if (temp-> right) s1.push(temp->right);

			}
		}
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
	vector<int> vec = ob.findSpiral(root);
	for (int x : vec) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
