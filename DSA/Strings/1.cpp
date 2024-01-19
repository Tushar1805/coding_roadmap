// Reveerse string II

#include<bits/stdc++.h>
using namespace std;

void solution1(string &s, int k) {
	for (int i = 0; i < s.size(); i += k) {
		if (i + k <= s.size()) {
			reverse(s.begin() + i, s.begin() + i + k);
		} else {
			reverse(s.begin() + i, s.end());
		}
	}
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	cin >> s;
	int k;
	cout << "Enter the value of k: ";
	cin >> k;

	// Brute Force
	solution1(s, k);
	cout << "Reversed string: " << s;
	return 0;
}