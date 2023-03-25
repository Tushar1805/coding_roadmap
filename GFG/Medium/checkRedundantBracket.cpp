// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

// Expression contains redundant bracket or not

// Given a string of balanced expression, find if it contains a redundant parenthesis or not. 
// A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. 
// Print Yes if redundant, else No.

// Note: Expression may contain + , - , *, and / operators. 
// Given expression is valid and there are no white spaces present.

// Example 1:

// Input:
// exp = ((a+b))
// Output:
// Yes
// Explanation:
// ((a+b)) can reduced to (a+b).
// Example 2:

// Input:
// exp = (a+b+(c+d))
// Output:
// No
// Explanation:
// (a+b+(c+d)) doesn't have any redundant or multiple
// brackets.
// Your task:

// You don't have to read input or print anything. 
// Your task is to complete the function checkRedundancy() 
// which takes the string s as input and returns 1 if it contains redundant parentheses else 0.

// Constraints:

// 1<=|str|<=104

#include<bits/stdc++.h>
using namespace std;

int checkRedundancy(string s) {
    stack<char> st;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
            st.push(s[i]);
        }
        if(s[i] == '(')
            st.push(s[i]);
        if(s[i] == ')'){
            if(st.top() == '('){
                ans = 1;
            }
            while(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/'){
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	string exp;
	int res;
	cout<<"Enter the expression to check redundancy of parenthesis: ";
	cin>>exp;
	res = checkRedundancy(exp);
	if(res == 1)
		cout<<"\nParenthesis in "<<exp<<" are redundant";
	else
		cout<<"\nParenthesis in "<<exp<<" are not redundant";
	return 0;
}