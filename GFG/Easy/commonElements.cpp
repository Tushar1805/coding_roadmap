// https://practice.geeksforgeeks.org/problems/common-elements1132/1?page=1&difficulty[]=0&sortBy=submissions

// Common elements

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// Example 1:

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.
 
// Your Task:  
// You don't need to read input or print anything. Y
// our task is to complete the function commonElements() 
// which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs 
// and returns an array containing the common element present in all the 3 arrays in sorted order. 
// If there are no such elements return an empty array. In this case the output will be printed as -1.

// Expected Time Complexity: O(n1 + n2 + n3)
// Expected Auxiliary Space: O(n1 + n2 + n3)

// Constraints:
// 1 <= n1, n2, n3 <= 10^5
// The array elements can be both positive or negative integers.

#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> ans;
    unordered_map<int, int> m1, m2, m3;
    for(int i=0;i<n1;i++) m1[a[i]]++;
    for(int i=0;i<n2;i++) m2[b[i]]++;
    for(int i=0;i<n3;i++) m3[c[i]]++;
    
    for(int i=0;i<n1;i++){
        if(m1[a[i]] and m2[a[i]] and m3[a[i]]){
            ans.push_back(a[i]);
            m1[a[i]] = 0;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	int n1, n2, n3;
	cout<<"Enter the size of 3 arrays respectively: ";
	cin>>n1>>n2>>n3;
	int a[n1], b[n2], c[n3];
	vector<int> ans;
	cout<<"\nEnter the elements of array 1: ";
	for (int i = 0; i < n1; ++i)
		cin>>a[i];
	
	cout<<"\nEnter the elements of array 2: ";
	for (int i = 0; i < n2; ++i)
		cin>>b[i];
	
	cout<<"\nEnter the elements of array 3: ";
	for (int i = 0; i < n3; ++i)
		cin>>c[i];

	ans = commonElements(a, b, c, n1, n2, n3);

	if(ans.size() != 0){
		cout<<"\nCommon elements: ";
		for (int i = 0; i < ans.size(); ++i)
			cout<<ans[i]<<" ";
	}else
		cout<<"\nNo common elements";
	return 0;
}