#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of rows: ";
	cin >> n;
	int l;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)
			l = 0;
		else
			l = 1;
		for (int j = 1; j <= i; j++) {
			cout << l << " ";
			l = 1 - l;
		}
		cout << endl;
	}
	return 0;
}