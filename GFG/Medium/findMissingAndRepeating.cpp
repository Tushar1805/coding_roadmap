//! Find Missing And Repeating

// Given an unsorted array Arr of size N of positive integers.
// One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array.
// Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and
// smallest positive missing number is 1.
// Example 2:

// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and
// smallest positive missing number is 2.
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function findTwoElement()
// which takes the array of integers arr and n as parameters
// and returns an array of integers of size 2 denoting the answer
// ( The first index contains B and second index contains A.)

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ N

#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> a, int n) {

	//! Brute Force Approach TC - O(n) SC - O(n)
	// unordered_map<int, int> m;
	// int rept;
	// for(int i=0; i<n;i++){
	//     m[arr[i]]++;
	//     if(m[arr[i]]>1){
	//         rept = arr[i];
	//     }
	// }
	// int k =1;
	// while(true){
	//     if(m[k]>0){
	//         k++;
	//     }else{
	//         break;
	//     }
	// }

	//! Optimized mathematical approach TC - O(n) SC- O(1)
	long long int N = n;
	long long int SN = (N * (N + 1) / 2);
	long long int S2N = (N * (N + 1) * (2 * N + 1) / 6);
	long long S = 0, S2 = 0;
	for (int i = 0; i < n; i++) {
		S += (long long) a[i];
		S2 += (long long) a[i] * (long long) a[i];
	}
	long long val1 = S - SN; // X - Y
	long long val2 = S2 - S2N; // X^2 - Y^2;
	val2 = val2 / val1;
	long long x = (val1 + val2) / 2; // repetiting
	long long y = x - val1; // missing

	vector<int> ans = {(int)x, (int)y};
	return ans;

}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> a;
	cout << "\nEnter " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
	vector<int> ans = findTwoElement(a, n);
	cout << "\nRepeating number: " << ans[0] << endl;
	cout << "Missing numbser: " << ans[1];
	return 0;
}