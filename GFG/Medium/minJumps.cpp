// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&sortBy=submissions

//Minimum number of jumps

// Given an array of N integers arr[] where each element represents the maximum length of 
// the jump that can be made forward from that element. This means if arr[i] = x, 
// then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). 
// If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.


// Example 1:

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to the last. 
// Example 2:

// Input :
// N = 6
// arr = {1, 4, 3, 2, 6, 7}
// Output: 2 
// Explanation: 
// First we jump from the 1st to 2nd element 
// and then jump to the last element.

// Your task:
// You don't need to read input or print anything. 
// Your task is to complete function minJumps() which takes the array arr and 
// it's size N as input parameters and returns the minimum number of jumps. If not possible return -1.


// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)


// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ arri ≤ 107

#include<bits/stdc++.h>
using namespace std;

int minJumps(int a[], int n){
        int steps = a[0];
        int maxR = a[0];
        int jumps = 1;
        if(n == 1) return 0;
        else if (a[0] == 0) return -1;
        else{
            for(int i=1; i<n;i++){
                if(i == n-1)
                    return jumps;
                maxR = max(maxR, i+a[i]);
                steps--;
                if(steps == 0){
                    jumps++;
                    if(i >= maxR)
                        return -1;
                    steps = maxR-i;
                }
            }
        }
        return jumps;
    }

int main(int argc, char const *argv[])
{
	int n;\
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter maximum length of jump each element can represent: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int jumps = minJumps(a, n);
	cout<<"\nThe minimum jumps required are: "<<jumps;
	return 0;
}