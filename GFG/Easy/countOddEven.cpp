// Count Odd Even

// https://practice.geeksforgeeks.org/problems/count-odd-even/0

// Given an array A[] of N elements. The task is to count number of even and odd elements in the array.

// Example:

// Input:
// N = 5
// A[] = 1 2 3 4 5
// Output:
// 3 2
// Explanation:
// There are 3 odd elements (1, 3, 5)
// and 2 even elements (2 and 4).
// Your Task:
// Your task is to complete the function countOddEven() which should print number of odd 
// nd number of even elements in a single line seperated by space.
// Print a newline at the end of output.

// Constraints:
// 1 <= N <= 106
// 1 <= Ai <= 106

#include<bits/stdc++.h>
using namespace std;


void countOddEven(vector<int> &a, int sizeof_array){
    int even = 0, odd = 0;
    for(int i = 0; i<sizeof_array; i++){
        if(a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    cout<<"ODD: "<<odd<<"  "<<"EVEN: "<<even<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
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
	countOddEven(a, n);
}