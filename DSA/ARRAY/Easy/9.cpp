#include<bits/stdc++.h>
using namespace std;

void solution1(vector<int> arr1, vector<int> arr2, int m, int n) {
	// Solution 1: Using a map
	// We are using map not unordered_map, map will sort the keys (it takes O(nlogn) TC)
	map<int, int> mp;
	vector<int> unionArr;

	for (int i = 0; i < m; i++)
		mp[arr1[i]]++;

	for (int i = 0; i < n; i++)
		mp[arr2[i]]++;

	for (auto i : mp)
		unionArr.push_back(i.first);


	cout << "Union Array: ";
	for (int i = 0; i < unionArr.size(); i++)
		cout << unionArr[i] << " ";
}

void solution2(vector<int> arr1, vector<int> arr2, int m, int n) {
	// Not using unordered_set, cause it will store elements in random order
	// but we want element in ascending order
	set < int > s;
	vector < int > Union;
	for (int i = 0; i < n; i++)
		s.insert(arr1[i]);
	for (int i = 0; i < m; i++)
		s.insert(arr2[i]);
	for (auto & it : s)
		Union.push_back(it);
	cout << "Union Array: ";
	for (int i = 0; i < Union.size(); i++)
		cout << Union[i] << " ";
}

void solution3(vector<int> arr1, vector<int> arr2, int m, int n) {
	//! Two Pointers approach
	int i = 0, j = 0; // pointers
	vector < int > Union; // Uninon vector
	while (i < m && j < n) {
		if (arr1[i] <= arr2[j]) // Case 1 and 2
		{
			if (Union.size() == 0 || Union.back() != arr1[i])
				Union.push_back(arr1[i]);
			i++;
		} else // case 3
		{
			if (Union.size() == 0 || Union.back() != arr2[j])
				Union.push_back(arr2[j]);
			j++;
		}
	}
	while (i < m) // IF any element left in arr1
	{
		if (Union.back() != arr1[i])
			Union.push_back(arr1[i]);
		i++;
	}
	while (j < n) // If any elements left in arr2
	{
		if (Union.back() != arr2[j])
			Union.push_back(arr2[j]);
		j++;
	}

	cout << "Union Array: ";
	for (int i = 0; i < Union.size(); i++)
		cout << Union[i] << " ";
}

int main(int argc, char const *argv[])
{
	int m, n;
	cout << "Enter the size of the array 1: ";
	cin >> m;
	cout << "Enter the " << m << " elements of the array 1: ";
	vector<int> arr1;
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		arr1.push_back(data);
	}
	cout << "Enter the size of the array 2: ";
	cin >> n;
	cout << "Enter the " << n << " elements of the array 2: ";
	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr2.push_back(data);
	}

	// solution1(arr1, arr2, m, n);
	// solution2(arr1, arr2, m, n);
	solution3(arr1, arr2, m, n);
	return 0;
}