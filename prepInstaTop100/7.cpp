// https://prepinsta.com/c-program/leap-year-or-not/

#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int y;
	cout<<"Enter the year: ";
	cin>>y;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		cout<<"\nIt's a leap year";
	else
		cout<<"\nIt's not a leap year";
	return 0;
}