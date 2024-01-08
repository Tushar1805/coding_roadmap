// Game of XOR
// To find the xor of all the subarrays
#include<bits/stdc++.h>
using namespace std;


// Optimal Approach: slight observations
// xor of two same numbers is 0 and different numbers is not zero
// so the if the array size is even it will give xor 0
// else we need to xor elements at even position in array
int solution1(vector<int> arr, int n) {
	int ans = 0;
	if (n % 2 == 0) return 0;
	for (int i = 0; i < n; i += 2) {
		ans ^= arr[i];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> arr;
	cout << "Enter the " << n << " elements of the array: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	// Optimal Force
	int ans = solution1(arr, n);
	cout << "XOR of all subarrays: " << ans;
	return 0;
}