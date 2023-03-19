// Printing array elements in alternate order

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter array elements: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nArray elements in alternate order: ";
	for (int i = 0; i < n; ++i)
	{
		if(i%2 == 0)
			cout<<a[i]<<" ";
	}
	return 0;
}