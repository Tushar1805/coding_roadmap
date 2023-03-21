// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

// Sales by Match

// There is a large pile of socks that must be paired by color. 
// Given an array of integers representing the color of each sock, 
// determine how many pairs of socks with matching colors there are.

// Example
// n =  7
// ar = [1, 2, 1, 2, 1, 3, 2]

// There is one pair of color 1 and one of color 2. 
// There are three odd socks left, one of each color. The number of pairs is 2.

// Function Description

// Complete the sockMerchant function in the editor below.

// sockMerchant has the following parameter(s):

// int n: the number of socks in the pile
// int ar[n]: the colors of each sock
// Returns

// int: the number of pairs

#include <bits/stdc++.h>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int > mm;
    int c =0;
    for (int i=0;i<n;i++) {
        mm[ar[i]]++;
        if(mm[ar[i]] % 2 == 0)
            c++;
    }
    return c;
}

int main(int argc, char const *argv[])
{
	int n, k, r;
	vector<int> ar;
	cout<<"Enter the number of socks present: ";
	cin>>n;
	cout<<"\nEnter values of socks: ";
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		ar.push_back(val);
	}

	cout<<"\nThere are "<<sockMerchant(n, ar)<<" pairs of socks";
	return 0;
}