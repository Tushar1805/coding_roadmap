#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int m = -1;
	for (int i = 0; i < n; i++) {
		for (int l = n - 1; l > i; l--) {
			cout << "  ";
		}
		for (int k = 0; k < m + 2; k++) {
			if (k == 0 || k == m + 1) {
				cout << "* ";
			} else {
				cout << "  ";
			}
		}
		m += 2;
		cout << endl;
	}
	return 0;
}