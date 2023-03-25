// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&sortBy=submissions

// Parenthesis Checker

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

// Example 1:

// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balanced pairs, with 0 number of 
// unbalanced bracket.
// Example 2:

// Input: 
// ()
// Output: 
// true
// Explanation: 
// (). Same bracket can form balanced pairs, 
// and here only 1 type of bracket is 
// present and in balanced way.
// Example 3:

// Input: 
// ([]
// Output: 
// false
// Explanation: 
// ([]. Here square bracket is balanced but 
// the small bracket is not balanced and 
// Hence , the output will be unbalanced.
// Your Task:
// This is a function problem. You only need to complete the function ispar() 
// that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. 
// The printing is done automatically by the driver code.

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 32000

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

bool ispar(string x)
{
   stack<char> s;
   int len = x.length();
   if(len % 2 !=0)
        return false;
   for(int i=0;i<len;i++){
       if(x[i] == '{' || x[i] == '[' || x[i] == '('){
           s.push(x[i]);
       }else{
           if(s.size() == 0)
                return false;
           char ch = s.top();
           if(x[i] == '}' && ch != '{')
                return false;
            else if(x[i] == ']' && ch != '[')
                return false;
            else if(x[i] == ')' && ch != '(')
                return false;
            s.pop();
       }
   }
   if(s.size() >0)
    return false;
    else
    return true;
}

int main(int argc, char const *argv[])
{
	string x;
	bool check;
	cout<<"Enter the string of parenthesis to check: ";
	cin>>x;
	check = ispar(x);
	if(check)
		cout<<"\nParanthesis string "<<x<<" is balanced";
	else
		cout<<"\nParanthesis string "<<x<<" is not balanced";
	return 0;
}