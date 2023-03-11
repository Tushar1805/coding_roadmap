/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/one-week-preparation-kit-plus-minus/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-one


// Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. 
// Print the decimal value of each fraction on a new line with 6 places after the decimal.

// Note: This challenge introduces precision problems. 
// The test cases are scaled to six decimal places, 
// though answers with absolute error of up to 10^-4 are acceptable.

// Function Description

// Complete the plusMinus function in the editor below.

// plusMinus has the following parameter(s):

// int arr[n]: an array of integers
// Print
// Print the ratios of positive, negative and zero values in the array. 
// Each value should be printed on a separate line with 6 digits after the decimal. 
// The function should not return a value.

// Input Format

// The first line contains an integer,n, the size of the array.
// The second line contains n space-separated integers that describe arr[n].

#include<iostream>
#include<vector>
using namespace std;

void plusMinus(vector<int> arr) {
    float pos = 0, neg = 0, zer = 0;
    for(int i=0; i< arr.size(); i++){
        if (arr.at(i) < 0) 
            neg++;
        else if(arr.at(i)>0)
            pos++;
        else
            zer++;
    }
    printf("Proportion of positive values: %.6f\n", pos/arr.size());
    printf("Proportion of Negative values: %.6f\n", neg/arr.size());
    printf("Proportion of Zeroes: %.6f", zer/arr.size());
}

int main(int argc, char const *argv[])
{
	int n;
	vector<int> arr;
	cout<<"Enter total number of positive, negative and zero values present in array: ";
	cin>>n;
	cout<<"\nEnter "<<n<<" values: ";
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		arr.push_back(val);
	}
	plusMinus(arr);
	return 0;
}