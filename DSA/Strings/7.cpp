// Longest common prefix

#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> strs, int n) {
	string ans = strs[0];
	for (int i = 1; i < n; i++) {
		int j = 0;
		string currentWord = strs[i];
		while (j < ans.length() && j < currentWord.length() && ans[j] == currentWord[j]) {
			j++;
		}
		if (j == 0) return "-1";
		ans = currentWord.substr(0, j);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	vector<string> strs;
	int n;
	cout << "Enter the number of string present in the array: ";
	cin >> n;
	cout << "Enter " << n << " strings\n";
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		strs.push_back(s);
	}

	string ans = solution(strs, n);
	cout << "Longest common prefix: " << ans;
	return 0;
}