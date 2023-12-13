#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

int solution1(vector<int> arr, int n) {
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 0; j < arr.size(); j++) {
			if (i == arr[j]) {
				flag = false;
				break;
			}
		}
		if (flag) return i;
	}
}

int solution2(vector<int> arr, int n) {
	unordered_map<int, int> mp;
	for (int i = 0; i < arr.size(); i++) {
		mp[arr[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (mp[i] == 0) return i;
	}
}

int solution3(vector<int> arr, int n) {
	int sn = n * (n + 1) / 2;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	return sn - sum;
}

int solution4(vector<int> arr, int n) {
	int xor1 = 0;
	int xor2 = 0;
	for (int i = 0; i < n - 1; i++) {
		xor1 ^= arr[i];
		xor2 ^= i + 1;
	}
	xor2 ^= n;
	return xor1 ^ xor2;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n - 1 << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n - 1; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	// int missing = solution1(arr, n);
	// int missing = solution2(arr, n);
	// int missing = solution3(arr, n);
	int missing = solution4(arr, n);


	cout << "Missing number: " << missing;
	return 0;
}