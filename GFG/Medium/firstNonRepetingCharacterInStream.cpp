//! First non-repeating character in a stream

// Given an input stream A of n characters consisting only of lower case alphabets.
// While reading characters from the stream, you have to tell which character
// has appeared only once in the stream upto that point. If there are many
// characters that have appeared only once, you have to tell which one of them
// was the first one to appear. If there is no such character then append '#' to the answer.

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'
// Example 2:

// Input: A = "zz"
// Output: "z#"
// Explanation: For every character first non
// repeating character is as follow-
// "z" - first non-repeating character is 'z'
// "zz" - no non-repeating character so '#'

// Your Task:
// You don't need to read or print anything.
// Your task is to complete the function FirstNonRepeating()
// which takes A as input parameter and returns a string after processing the input stream.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= n <= 105

#include<bits/stdc++.h>
using namespace std;

//! Bruete Force TC- O(n^2s)
// string FirstNonRepeating(string str) {
// 	// Code here
// 	string A, ans;
// 	for (auto q : str) {
// 		A += q;
// 		map<char, int> m;
// 		for (auto i : A) {
// 			m[i] += 1;
// 		}
// 		int flag = -1;
// 		for (int i = 0; i < A.length(); i++) {
// 			if (m[A[i]] == 1) {
// 				flag = i;
// 				break;
// 			}
// 		}
// 		if (flag == -1)
// 			ans += '#';
// 		else
// 			ans += A[flag];
// 	}
// 	return ans;
// }

//! Optimized Approach
string FirstNonRepeating(string A) {
	map<char, int> m;
	string ans = "";
	queue<char> q;
	for (int i = 0; i < A.size(); i++) {
		q.push(A[i]);
		m[A[i]] += 1;
		while (!q.empty()) {
			if (m[q.front()] == 1) {
				ans.push_back(q.front());
				break;
			} else {
				q.pop();
			}
		}
		if (q.empty())
			ans.push_back('#');
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter a string: ";
	cin >> s;
	string  ans =  FirstNonRepeating(s);
	cout << "Answer: " << ans;
	return 0;
}