// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?page=1&category[]=Strings&sortBy=submissions

// Reverse words in a given string

// Given a String S, reverse the string without reversing its individual words. 
// Words are separated by dots.

// Example 1:

// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole
// string(not individual words), the input
// string becomes
// much.very.program.this.like.i
// Example 2:

// Input:
// S = pqr.mno
// Output: mno.pqr
// Explanation: After reversing the whole
// string , the input string becomes
// mno.pqr

// Your Task:
// You dont need to read input or print anything. 
// Complete the function reverseWords() which takes string S as input parameter and 
// returns a string containing the words in reversed order. Each word in the returning 
// string should also be separated by '.' 

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)

// Constraints:
// 1 <= |S| <= 105

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{ 
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
    str = tmp[tmp.size()-1];
    int i;
    for (i = tmp.size() - 2; i >= 0; i--)
        str = str + "." += tmp[i] ;
    return str;
} 

int main(int argc, char const *argv[])
{
	string s, res;
	cout<<"Enter the string of words (words seperated with dots): ";
	cin>>s;
	res = reverseWords(s);
	cout<<"\nReversed string of words: "<<res;
	return 0;
}