// Finding Majority Element in an Array

// A Majority Element in an array is a element whose frequency in the array is greater then 
// the half of the length of the array. 
// For Ex. Arr={1, 2, 1, 1, 4, 3,  4, 4, 4, 4, 4, 3} , 
// Here n(length of the array) = 11, n/2 = 5, Frequency of  4 is  6 ie. > n/2. 
// So, the majorityelement in this array is 4.

#include<iostream>
#include<unordered_map>
using namespace std;

int getMajorityElement(int  n, int a[]){
	unordered_map<int, int> mm;
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		mm[a[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(mm[a[i]] > n/2)
			max = a[i];
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int n;
	
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nMajority element in the array is: "<<getMajorityElement(n, a);

	return 0;
}