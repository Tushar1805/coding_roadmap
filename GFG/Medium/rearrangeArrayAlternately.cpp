//! Rearrange Array Alternately

// Given a sorted array of positive integers.
// Your task is to rearrange the array elements alternatively
// i.e first element should be max value, second should be min value, third should be second max,
// fourth should be second min and so on.
// Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

// Example 1:

// Input:
// n = 6
// arr[] = {1,2,3,4,5,6}
// Output: 6 1 5 2 4 3
// Explanation: Max element = 6, min = 1,
// second max = 5, second min = 2, and
// so on... Modified array is : 6 1 5 2 4 3.
// Example 2:

// Input:
// n = 11
// arr[]={10,20,30,40,50,60,70,80,90,100,110}
// Output:110 10 100 20 90 30 80 40 70 50 60
// Explanation: Max element = 110, min = 10,
// second max = 100, second min = 20, and
// so on... Modified array is :
// 110 10 100 20 90 30 80 40 70 50 60.
// Your Task:
// The task is to complete the function rearrange()
// which rearranges elements as explained above.
// Printing of the modified array will be handled by driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 10^6
// 1 <= arr[i] <= 10^7

#include<bits/stdc++.h>
using namespace std;

void swap(long long *a, long long *b) {
	long long temp = *a;
	*a = *b;
	*b = temp;
}
void rearrange(long long *arr, int n)
{
	//     long long ans[n];
	//     long long int i=0;
	//     long long int s=0, e = n-1;
	//     bool max=true;
	// 	while(s<=e){
	// 	    if(max){
	// 	        ans[i] = arr[e];
	// 	        max= false;
	// 	        e--;
	// 	        i++;
	// 	    }else{
	// 	        ans[i] = arr[s];
	// 	        max = true;
	// 	        s++;
	// 	        i++;
	// 	    }
	// 	}
	// 	for(int j=0;j<n;j++){
	// 	    arr[j] = ans[j];
	// 	}

	//! Optimized approach
	int maxIndex = n - 1;
	int minIndex = 0;
	int max = arr[n - 1] + 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			arr[i] = (arr[maxIndex] % max) * max + arr[i];
			maxIndex--;
		} else {
			arr[i] = (arr[minIndex] % max) * max + arr[i];
			minIndex++;
		}
	}
	for (int i = 0; i < n; i++)
		arr[i] /= max;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "\nEnter " << n << " elements of array: ";
	long long int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	rearrange(a, n);
	cout << "\nArray after rearranging according to given criteria: ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}