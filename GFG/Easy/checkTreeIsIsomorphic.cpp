//! Check if Tree is Isomorphic

// Given two Binary Trees. Check whether they are Isomorphic or not.

// Note:
// Two trees are called isomorphic if one can be obtained from another by a series of flips,
// i.e. by swapping left and right children of several nodes. Any number of nodes
// at any level can have their children swapped. Two empty trees are isomorphic.
// For example, the following two trees are isomorphic with the following sub-trees
// flipped: 2 and 3, NULL and 6, 7 and 8.
// ISomorphicTrees

// Example 1:

// Input:
//  T1    1     T2:   1
//      /   \        /  \
//     2     3      3    2
//    /            /
//   4            4
// Output: No

// Example 2:

// Input:
// T1    1     T2:    1
//     /  \         /   \
//    2    3       3     2
//   /                    \
//   4                     4
// Output: Yes
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function isomorphic()
// that takes the root nodes of both the Binary Trees as its input and
// returns True if the two trees are isomorphic. Else, it returns False.
// (The driver code will print Yes if the returned values are true, otherwise false.)

// Expected Time Complexity: O(min(M, N)) where M and N are the sizes of the two trees.
// Expected Auxiliary Space: O(min(H1, H2)) where H1 and H2 are the heights of the two trees.

// Constraints:
// 1<=Number of nodes<=105

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val) {
		data = val;
		left = right = NULL;
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
	Node* root = new Node(stoi(ip[0]));

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
			currNode->left = new Node(stoi(currVal));

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
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

bool isIsomorphic(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 != NULL && root2 == NULL)
		return 0;
	if (root1 == NULL && root2 != NULL)
		return 0;
	if (root1 -> data != root2 -> data)
		return 0;
	return (isIsomorphic(root1 -> left, root2 -> left) && isIsomorphic(root1 -> right, root2 -> right)) || (isIsomorphic(root1->left, root2 -> right) && isIsomorphic(root1 -> right, root2 -> left));
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s1, s2;
		// cout << "Enter the elements of tree 1: ;
		getline(cin, s1);
		// cout << "Enter the elements of tree 2: ";
		getline(cin, s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		if (isIsomorphic(root1, root2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

