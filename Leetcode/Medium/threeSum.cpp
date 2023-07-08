//! 15. 3Sum

//! Follow up - triplet of sum m

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// Test Case - 3,0,-2,-1,1,2

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int m) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int j, k;
	vector<vector<int>> ans ;
	for (int i = 0; i < size; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		j = i + 1;
		k = size - 1;
		while (j < k) {
			if ((nums[i] + nums[j] + nums[k]) > m) {
				k--;
			} else if ((nums[i] + nums[j] + nums[k]) < m) {
				j++;
			} else {
				vector<int> temp;
				temp = {nums[i], nums[j], nums[k]};
				ans.push_back(temp);
				j++; k--;
				while (j < k && nums[j] == nums[j - 1]) j++;
				while (j < k && nums[k] == nums[k + 1]) k--;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> a;
	cout << "\nEnter " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
	int m;
	cout << "Enter a value you want triplet for: ";
	cin >> m;

	vector<vector<int>> ans = threeSum(a, m);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << "[";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}