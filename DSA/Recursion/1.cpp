#include<iostream>
using namespace std;

void print(int i) {
	if (i == 10) return;
	cout << i << endl;
	print(++i);
}

int main(int argc, char const *argv[])
{
	print(1);
	return 0;
}