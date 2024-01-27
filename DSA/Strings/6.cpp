// Largest odd number in a string

#include<bits/stdc++.h>
using namespace std;

// Will check the unit place from last for the odd numbers in the string
string solution1(string str) {
	int n = str.size();
	string ans = "";
	for (int i = n - 1; i >= 0; i--) {
		if ((str[i] - '0') % 2 == 1) {
			ans = str.substr(0, i + 1);
			break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string str;
	cout << "Enter the string: ";
	getline(cin, str);

	// Optimal Solution
	string ans = solution1(str);


	cout << "Largest odd number from the given string " << str << " is: " << ans;
	return 0;
}