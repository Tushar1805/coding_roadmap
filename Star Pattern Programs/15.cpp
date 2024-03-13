#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of rows to print: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 4 != 0) {
			for (int j = 1; j < 2 * (i % 4); j++) {
				cout << " ";
			}
		} else {
			for (int j = 1; j <= 3; j++) {
				cout << " ";
			}
		}
		cout << "*" << endl;
	}
	return 0;
}