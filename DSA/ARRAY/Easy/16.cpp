#include<bits/stdc++.h>
using namespace std;

static bool cmp(string a, string b) {
	return (a + b) > (b + a);
}
string getLargestNumber(vector<int> &arr, int n) {
	vector<string> strs;
	for (int i = 0; i < n; i++) {
		strs.push_back(to_string(arr[i]));
	}
	sort(strs.begin(), strs.end(), cmp);
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += strs[i];
	}
	if (ans[0] == '0') {
		ans.erase(1);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << "Elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	string ans = getLargestNumber(arr, n);
	cout << "Largest Number formed from the given array: " << ans;
	return 0;
}