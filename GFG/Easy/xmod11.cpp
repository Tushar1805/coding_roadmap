// https://practice.geeksforgeeks.org/problems/aa8c89caad6b5c3a76ba5e6d65454f77aac3f3543526/1

// Remainder on dividing by 11

// Given a big positive number x represented as string, find value of x % 11 or x mod 11. 
// Output is expected as an integer.

// Example 1:

// Input: x = 1345
// Output: 3
// Explanation: 1345 % 11 = 3 
// Example 1:

// Input: x = 231456786543567898765
// Output: 1
// Explanation: 231456786543567898765 % 11 = 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function xmod11() 
// which takes string x as the input parameter and returns the integer value of x%11.

// Expected Time Complexity: O(length of string x)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ length of string x ≤ 100000

#include<bits/stdc++.h>
using namespace std;

int xmod11(string s)
{
    int rem = 0, cur = 0;
    for(int i=0;i<s.length();i++){
        cur = rem * 10 + s.at(i) - '0';
        rem = cur % 11;
    }
    return rem;
}

int main(int argc, char const *argv[])
{
	string x;
	cout<<"Enter the string to divide it by 11: ";
	cin>>x;
	cout<<"\nThe remainder after dividing the string of numbers "<<x<<" is: "<<xmod11(x);
	return 0;
}