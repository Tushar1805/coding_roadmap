// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?page=1&difficulty[]=-1&sortBy=submissions

// First and last occurrences of x

// Given a sorted array arr containing n elements with possibly duplicate elements, 
// the task is to find indexes of first and last occurrences of an element x in the given array.

// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5. 
 
// Example 2:

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:  6 6 

// Your Task:
// Since, this is a function problem. You don't need to take any input, 
// as it is already accomplished by the driver code. 
// You just need to complete the function find() that takes array arr, 
// integer n and integer x as parameters and returns the required answer.
// Note: If the number x is not found in the array just return both index as -1.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 107

#include<bits/stdc++.h>
using namespace std;

vector<int> find(int a[], int n , int x )
{
    vector<int> ans;
    int l=0, r= n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
       if(a[mid] == x){
           ans.push_back(mid);
           r = mid -1;
       }else if (a[mid] < x){
           l = mid + 1;
       }else{
           r = mid -1;
       }
    }
    
    l = 0;
    r = n-1;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == x){
            ans.push_back(mid);
            l = mid+1;
        }else if(a[mid] < x){
            l = mid+1;
        }else{
            r = mid -1;
        }
    }
    
    if(ans.size() == 0) return {-1, -1};
    sort(ans.begin(), ans.end());
    return {ans[0], ans[ans.size() -1]};
}

int main(int argc, char const *argv[])
{
	int n, x;
	vector<int> res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the number to find the first and last occurence of: ";
	cin>>x;
	res = find(a, n, x);
	if(res[0] != -1 and res[1] != -1)
		cout<<"\nFirst occurence of "<<x<<" : "<< res[0] <<" & Last occurence of "<< x<< " : "<<res[1];
	else
		cout<<"\n"<<x<<" Not found in the array";
	return 0;
}