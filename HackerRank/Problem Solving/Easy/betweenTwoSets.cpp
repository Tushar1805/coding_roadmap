/********** Get Problem Here **********/
 // https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

// There will be two arrays of integers. Determine all integers that satisfy the following two conditions:

// 1. The elements of the first array are all factors of the integer being considered
// 2. The integer being considered is a factor of all elements of the second array

// These numbers are referred to as being between the two arrays. Determine how many such numbers exist.

// Function Description

// Complete the getTotalX function in the editor below. It should return the number of integers that are betwen the sets.

// getTotalX has the following parameter(s):

// int a[n]: an array of integers
// int b[m]: an array of integers
// Returns

// int: the number of integers that are between the sets

#include<bits/stdc++.h>
using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    std :: sort(a.begin(), a.end());
    std :: sort(a.begin(), a.end());
    
    int times_multiplied = 2;
    int count = 0;
    int num = a.back();
    while (num<= b.front()) {
        bool is_factor = true;
        bool is_multiple = true;
        
        for (int i = 0; i< a.size(); i++) {
            if (num % a.at(i) != 0) {
                is_multiple = false;
                break;
            }
        }
        
        for (int i = 0; i< b.size(); i++) {
            if (is_multiple && b.at(i) % num !=0) {
                is_factor = false;
                break;
            }
        }
        
        if (is_multiple && is_factor ) {
            count++;
        }
        num = a.back() * times_multiplied;
        times_multiplied ++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
	int m, n;
	vector<int> a, b;
	cout<<"Enter the size of array a & b: ";
	cin>>m>>n;
	cout<<"\nEnter the elements of array a: ";
	for (int i = 0; i < m; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	cout<<"\nEnter the elements of array b: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		b.push_back(value);
	}
	cout<<"Number of integers present according to the condition between sets: "<<getTotalX(a, b);
	return 0;
}