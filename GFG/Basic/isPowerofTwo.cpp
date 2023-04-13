// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1?page=1&difficulty[]=-1&sortBy=submissions

// Power of 2

// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, 
// check if N can be expressed as 2x for some x.

// Example 1:

// Input: N = 1
// Output: YES
// Explanation:1 is equal to 2 
// raised to 0 (20 = 1).
// Example 2:

// Input: N = 98
// Output: NO
// Explanation: 98 cannot be obtained
// by any power of 2.

// Your Task:Your task is to complete the function isPowerofTwo() which takes n as a parameter 
// and returns true or false by checking if the given number can be represented as a power of two or not.

// Expected Time Complexity:O(log N).
// Expected Auxiliary Space:O(1).

// Constraints:
// 0 ≤N ≤1018

#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
        
    // O(log n) complexity
    if(n == 0)
        return false;
        
    while(n>1 && (n&1) == 0)
        n>>=1;
    
    return n==1 ? true : false;
    
    
    // O(1) complexity
    // if(n == 0)
    //     return false;
        
    // return floor(log2(n)) == ceil(log2(n)) ? true: false;
    
}

int main(int argc, char const *argv[])
{
	long long int n;
	cout<<"Enter any positive integer to check if it is power of two or not: ";
	cin>>n;
	if(isPowerofTwo(n))
		cout<<endl<<n<<" is the power of 2";
	else
		cout<<endl<<"Not a power of 2";
	return 0;
}