// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?page=4&difficulty[]=0&sortBy=submissions

// Union of Two Sorted Arrays

// Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Given two sorted arrays of size n and m respectively, find their union.

// Example 1:

// Input: 
// n = 5, arr1[] = {1, 2, 3, 4, 5}  
// m = 3, arr2 [] = {1, 2, 3}
// Output: 1 2 3 4 5
// Explanation: Distinct elements including 
// both the arrays are: 1 2 3 4 5.
 
// Example 2:

// Input: 
// n = 5, arr1[] = {2, 2, 3, 4, 5}  
// m = 5, arr2[] = {1, 1, 2, 3, 4}
// Output: 1 2 3 4 5
// Explanation: Distinct elements including 
// both the arrays are: 1 2 3 4 5.
 
// Example 3:

// Input:
// n = 5, arr1[] = {1, 1, 1, 1, 1}
// m = 5, arr2[] = {2, 2, 2, 2, 2}
// Output: 1 2
// Explanation: Distinct elements including 
// both the arrays are: 1 2.

// Your Task: 
// You do not need to read input or print anything. 
// Complete the function findUnion() that takes two arrays arr1[], arr2[], 
// and their size n and m as input parameters and returns a list containing the union of the two arrays. 
 
// Expected Time Complexity: O(n+m).
// Expected Auxiliary Space: O(n+m).
 
// Constraints:
// 1 <= n, m <= 105
// 1 <= arr[i], brr[i] <= 106

#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int a[], int b[], int n, int m)
{
    vector<int> ans;
    unordered_map<int, int> mm;
    int i = 0, j= 0, k=0;
    // ans.push_back(a[k]);
    while(i<n && j<m){
        if(a[i] == b[j]){
            if(ans.size() !=0 && ans[k-1] != a[i]){
                ans.push_back(a[i]);
                k++;
            }else if(ans.size()==0){
                 ans.push_back(a[i]);
                k++;
            }
            i++;
            j++;
        }else if(a[i]<b[j]){
             if(ans.size() !=0 && ans[k-1] != a[i]){
                ans.push_back(a[i]);
                k++;
            }else if(ans.size()==0){
                 ans.push_back(a[i]);
                k++;
            }
            i++;
        }else{
             if(ans.size() !=0 && ans[k-1] != b[j]){
                ans.push_back(b[j]);
                k++;
            }else if(ans.size()==0){
                 ans.push_back(b[j]);
                k++;
            }
            j++;
        }
    }
    
    while(i<n){
        if(ans.size() !=0 && ans[k-1] != a[i]){
            ans.push_back(a[i]);
            k++;
        }else if(ans.size()==0){
                 ans.push_back(a[i]);
                k++;
        }
        i++;
    }
    
    while(j<m){
        if(ans.size() !=0 && ans[k-1] != b[j]){
            ans.push_back(b[j]);
            k++;
        }else if(ans.size()==0){
                 ans.push_back(b[j]);
                k++;
            }
        j++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	int n, m;
	vector<int> res;
	cout<<"Enter the size of array 1 and 2 respectively: ";
	cin>>n>>m;
	int a[n];
	int b[m];
	cout<<"\nEnter the "<< n<<" elements of array 1: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the "<< m<<" elements of array 2: ";
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	res = findUnion(a, b, n , m);
	if (res.size() != 0)
	{
		cout<<"\nUnion of Arrays: ";
		for (int i = 0; i < res.size(); ++i)
		{
			cout<<res[i]<<" ";
		}
	}else{
		cout<<"\nNo union";
	} 
	return 0;
}