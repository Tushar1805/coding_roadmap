// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/0

// Non Repeating Numbers

// Given an array A containing 2*N+2 positive numbers, 
// out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. 
// Find the other two numbers. Return in increasing order.

// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.
// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.

// Your Task:
// You do not need to read or print anything. 
// Your task is to complete the function singleNumber() which takes the array as input parameter 
// and returns a list of two numbers which occur exactly once in the array. 
// The list must be in ascending order.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= length of array <= 106 
// 1 <= Elements in array <= 5 * 106

#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums) 
{
    unordered_map<int, int> mm;
    vector<int> res;
    int n = nums.size();
    for(int i=0;i<n;i++){
        mm[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mm[nums[i]] == 1){
            res.push_back(nums[i]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	vector<int> a, res;
	cout<<"\nEnter "<<2*n+2<<" numbers in array: ";
	for (int i = 0; i < 2*n+2; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	res = singleNumber(a);
	cout<<"\nRESULT: ";
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}

