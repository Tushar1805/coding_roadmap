// Pairs in array with given sum

// https://prepinsta.com/cpp-program/find-pair-in-array-with-given-sum/

// Write a Program in C Programming Language where you need to find the pairs in Array with given sum.

// Input Format
//     -First line contains the value of n that is the total number of elements in the array
//     -Second line contains the elements of array
//     -Third line contains the Sum to be checked.

// Output Format
//     -Output contains as many lines as number of pairs with each pair written in each line
//     -Last line of output contains the total count of pairs.

// Sample Test Case : 1

// Input
// 7
// 5 2 3 4 1 6 7
// 7

// Output
// [5 2]
// [3 4]
// [1 6]
// Total Number of Pairs : 3

// Sample Test Case : 2

// Input
// 99
// 10 15 20 25 30 35 40 45 50
// 50

// Output
// [10 40]
// [15 35]
// [20 30]
// Total Number of Pairs : 3

// Simplest approach
// The simplest approach is that for every element we search for its counterpart 
// that makes the sum of both equal to the desired sum.
// Since we need to search for counterparts for each element 
// therefore the array had to be traversed completely for each element.
// Thus, the complexity of this program comes out to be O(n*n).

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, s, c = 0;
	vector<int> a;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements of array: ";
	for (int i = 0; i < n; ++i){
	 	int value;
	 	cin>>value;
	 	a.push_back(value);
	} 
	cout<<"Enter the sum for which pairs has to be checked in array: ";
	cin>>s;
	cout<<"\nPairs\n";
	for(int i = 0; i<n;i++){
		for(int j =i+1; j<n;j++){
			if((a[i] + a[j]) == s){
				cout<<a[i]<<" + "<<a[j]<<" = "<<s<<endl;
				c++;
			}
		}
	}
	cout<<"There are "<<c<<" pairs which matches the sum "<<s;
	return 0;
}