// https://leetcode.com/problems/rotate-array/description/

// 189. Rotate Array

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 
// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 
// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

#include<bits/stdc++.h>
using namespace std;

 void reverse(vector<int>& a, int low, int high){
    while(low<high){
        swap(a[low], a[high]);
        low++;
        high--;
    }
}
void rotate(vector<int>& a, int k) {
    int n = a.size();
    k = k % n;
    
    reverse(a, 0, n-k-1);
    reverse(a, n-k, n-1);
    reverse(a, 0, n-1);
}

int main(int argc, char const *argv[])
{
	int n,d;
	cout<<"Enter the size of the array: ";
	cin>>n;
	vector<int> a;
	cout<<"\nEnter the "<<n<<" elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	} 
	cout<<"\nEnter the value from where you want to rotate the array to right: ";
	cin>>d;
	rotate(a, d);
	cout<<"\nArray after rotation: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	} 
	return 0;
}