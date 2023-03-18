// First element to occur k times

// Given an array of N integers. Find the first element that occurs at least K number of times.
 

// Example 1:

// Input :
// N = 7, K = 2
// A[] = {1, 7, 4, 3, 4, 8, 7}
// Output :
// 4
// Explanation:
// Both 7 and 4 occur 2 times. 
// But 4 is first that occurs 2 times
// As at index = 4, 4 has occurred 
// atleast 2 times whereas at index = 6,
// 7 has occurred atleast 2 times.
 

// Your Task:  
// You don't need to read input or print anything. 
// Your task is to complete the function firstElementKTime() which takes the array A[], 
// its size N, and an integer K as inputs and returns the required answer. 
// If the answer is not present in the array, return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 104
// 1 <= K <= 100
// 1<= A[i] <= 200

#include<iostream>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, e = -1;
	cout<<"Enter the size of the two array: ";
	cin>>n;
	int a[n];
	unordered_map<int, int> m;
	cout<<"\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the frequency of occurence: ";
	cin>>k;
	for (int i = 0; i < n; ++i)
	{
		m[a[i]]++;
		if (m[a[i]] >= k){
			e = a[i];
			break;
		}
	}
	cout<<"\nThe first element in array which is occured "<<k<<" times is: "<<e;
	return 0;
}