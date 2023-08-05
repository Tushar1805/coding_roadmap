#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n ;
	cout << "enter number of rows: ";
	cin >> n;
	int l = 2 * (n - 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		for (int k = 1; k <= l; k++) {
			cout << "  ";
		}
		for (int j = i; j >= 1; j--) {
			cout << j << " ";
		}
		l -= 2;
		cout << endl;
	}

	return 0;
}