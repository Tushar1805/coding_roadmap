// 40. Permutations in which n people can occupy r seats in a classroom

//! Formula  =  n P r  =  n! / (n-r)!

#include<iostream>
using namespace std;

//function for factorial
int factorial(int num)
{
	int fact = 1;
	for (int i = num; i >= 1 ; i--)
		fact *= i;
	return fact;
}

int main(int argc, char const *argv[])
{
	int n, r;
	cout << "Enter the number of people present in the classroom: ";
	cin >> n;
	cout << endl << "Enter the number of seats present in the classroom: ";
	cin >> r;
	int p = factorial(n) / factorial(n - r);

	cout << "Total Possible Arrangements: " << p;
	return 0;
}