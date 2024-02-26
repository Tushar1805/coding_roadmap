// Sum of N natural numbers using recursion

#include<bits/stdc++.h>
using namespace std;

// Using parameterized recursion
void fn(int i, int sum) {
	if (i < 1) {
		cout << "Sum =  " << sum << endl;
		return;
	}
	fn(i - 1, sum + i);
}

// Using functional recursion
int fn(int i) {
	if (i == 0)
		return 0;
	return i + fn(i - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value fo N: ";
	cin >> n;
	fn(n, 0);
	cout << "Sum of " << n << " Natural numbers is " << fn(n) << endl;
	return 0;
}