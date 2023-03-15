// https://prepinsta.com/cpp-program/reverse-an-array-or-string/

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i=0; i<n/2; i++){
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = temp;
	}
	cout<<"\nArray in reversed order: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}