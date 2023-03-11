// Problem Statement: To find median among unsorted odd number of total numbers given in the array

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
 {
 	int n;
 	vector<int> arr;
 	cout<<"Enter any odd number: ";
 	cin>>n;
 	cout<<"\nEnter "<<n<<" number of integers: ";
 	for (int i = 0; i < n; ++i)
 	{
 		int value;
 		cin>>value;
 		arr.push_back(value);
 	}
 	sort(arr.begin(), arr.end());
 	cout<<"\nMedian: "<<arr.at(n/2);
 	return 0;
 } 