#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << "Elements of the array (1 & 0): ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	cout << "To find the consecutive one's in the above array" << endl;
	int count = 0;
	int i = 0;
	int max_count = INT_MIN;
	while (i < n) {
		if (arr[i] == 1) {
			count++;
		} else {
			count = 0;
		}
		max_count = max(max_count, count);
		i++;
	}
	cout << "Max count of consecutive one's: " << max_count;
	return 0;
}