/********** Get Problem Here **********/
 // https://www.hackerrank.com/challenges/one-week-preparation-kit-mini-max-sum/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-one

//  Given five positive integers, 
//  find the minimum and maximum values that can be calculated by summing exactly four of the five integers. 
//  Then print the respective minimum and maximum values as a single line of two space-separated long integers.


//  Example

//  arr = [1, 3, 5, 7, 9]

// The minimum sum is 1+3+5+9 = 16 and 
// the maximum sum is 3+5+7+9 = 24. 
// The function prints
// 16 24

// Function Description

// Complete the miniMaxSum function in the editor below.

// miniMaxSum has the following parameter(s):

// arr: an array of  integers

#include <iostream>
#include <vector>
using namespace std;

void miniMaxSum(vector<int> arr) {
    long long int min = INT_LEAST64_MAX, max = 0;
    for (int i=0; i<arr.size(); i++) {
        long long int sum =0;
        for (int j=0; j<arr.size(); j++) {
            if(i != j){
                sum += arr.at(j);
            }
        }
        if (sum< min) 
            min = sum;
        if (sum>max) 
            max = sum;
    }
    printf("\nMinimum: %lld & Maximum: %lld", min, max);
}

int main(int argc, char const *argv[])
{
	vector<int> arr;
	cout<<"Enter any 5 positive integers: ";
	for (int i = 0; i < 5; ++i)
	{
		int value;
		cin>>value;
		arr.push_back(value);
	}
	miniMaxSum(arr);
	return 0;
}