// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/0

// Generate Parentheses

// Given an integer N representing the number of pairs of parentheses, 
// the task is to generate all combinations of well-formed(balanced) parentheses.

// Example 1:

// Input:
// N = 3
// Output:
// ((()))
// (()())
// (())()
// ()(())
// ()()()
// Example 2:
// Input:
// N = 1
// Output:
// ()

// Your Task:  
// You don't need to read input or print anything. Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

// Expected Time Complexity: O(2N * N).
// Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

// Constraints:
// 1 ≤ N ≤ 12

#include<bits/stdc++.h>
using namespace std;

void findAll(string current, int o, int c, vector<string> &res, int n){
    if(o == n && c == n){
        res.push_back(current);
        return;
    }
    if(o<n){
        findAll(current+"(", o+1, c, res, n);
    } 
    if(c<o){
        findAll(current+")", o, c+1, res, n);
    } 
}
vector<string> AllParenthesis(int n) 
{
    vector<string> res;
    findAll("", 0, 0, res, n);
    return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the value of n upto n to generate valid parentheses: ";
	cin>>n;
	vector<string> res = AllParenthesis(n);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<"\n"<<res[i];
	}
	return 0;
}