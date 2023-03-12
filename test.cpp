#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// int a[] = {67, 82, 65, 67, 75, 32, 84, 72, 69, 32, 67, 79, 68, 69};
	// printf("***********Output************\n");
	// for (int i = 0; i < 14; ++i)
	// {
	// 	printf("%c", a[i]);
	// }
	// int ascii = 98;
	// char a = ascii;
	// cout<<a;

	// //Precision
	// int  a = 1, b = 5;
	// printf("R: %.6f", a/b);

	// Vector Sorting
	vector<int> a ;
	cout<<"Enter the elements: ";
	for (int i = 0; i < 3; ++i)
	{
		int value ;
		cin>>value;
		a.push_back(value);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i)
	{
		cout<<a.at(i)<< " " ;
	}
	return 0;
}