#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n ;
	cout << "Enter the value of n: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int l = i; l < n; l++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 0; j < i - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = n; i > 0; i--) {
		for (int j = n; j >= i; j--) {
			cout << "*";
		}
		for (int l = 0; l < i - 1; l++) {
			cout << " ";
		}
		for (int l = 1; l < i - 1; l++ ) {
			cout << " ";
		}
		for (int j = n; j >= i; j--) {
			if (j == 1) {
				break;
			}
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}