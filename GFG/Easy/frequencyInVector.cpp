// Find the Frequency

// https://practice.geeksforgeeks.org/problems/find-the-frequency/0

// Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

// Example 1:

// Input:
// N = 5
// vector = {1, 1, 1, 1, 1}
// X = 1
// Output: 
// 5
// Explanation: Frequency of 1 is 5.
// Your Task:
// Your task is to complete the function findFrequency() which should count the frequency of X and return it.

#include<bits/stdc++.h>
using namespace std;

int findFrequency(vector<int> v, int x){
	int f = 0;
	for(int i = 0; i<v.size(); i++){
	    if(v[i] == x)
	        f++;
	}
	return f;
}

int main(int argc, char const *argv[])
{
	int n, res, x;
	vector<int> a;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	cout<<"\nEnter a number to find frequency of: ";
	cin>>x;
	res = findFrequency(a, x);
	cout<<"\n"<<x<<" appered "<<res<<" times in the array";
}