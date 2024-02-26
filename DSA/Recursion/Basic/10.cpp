#include<iostream>
using namespace std;

void reverse(string& str, int i = 0) {
	if (str.length() / 2 == i)
		return;
	swap(str[i], str[str.length() - i - 1]);
	i++;
	reverse(str, i);
}

int main(int argc, char const *argv[])
{
	string str;
	cout << "Enter a string: ";
	cin >> str;
	string org = str;
	reverse(str);
	if (org == str)
		cout << "Given string " << org << " is a palindrome";
	else
		cout << "Not palindrome";
	return 0;
}