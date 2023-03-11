/********** Get Problem Here **********/
//https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true&h_r=next-challenge&h_v=zen


// Given an array of integers and a positive integer k, 
// determine the number of (i, j) pairs where i<j and a[i] + a[j] is divisible by k.

// Example
// ar = [1, 2, 3, 4, 5, 6]
// k = 5

// Three pairs meet the criteria: [1, 4], [2, 3] and [4, 6].

// Function Description

// Complete the divisibleSumPairs function in the editor below.

// divisibleSumPairs has the following parameter(s):

// int n: the length of array ar
// int ar[n]: an array of integers
// int k: the integer divisor
// Returns
// - int: the number of pairs

#include<iostream>
#include <vector>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count  = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j< n ; j++) {
            if ((ar.at(i) + ar.at(j)) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
	int n, k, r;
	vector<int> ar;
	cout<<"Enter the length of array and the integer by which elements of array being divided: ";
	cin>>n>>k;
	cout<<"\nEnter "<<n<<" elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		ar.push_back(val);
	}
	r = divisibleSumPairs(n,  k, ar);
	cout<<"\n\nThere are "<<r<<" pairs which satisfies the condition";
	return 0;
}