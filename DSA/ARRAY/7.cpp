// Sort the array in Waveform

#include <iostream>
using  namespace std;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the array elements: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for (int i = 0; i < n; i = i+2)
	{
		if(i > 0 && a[i]<a[i-1])
			swap(&a[i], &a[i-1]);
		if(i<n-1 && a[i]<a[i+1])
			swap(&a[i], &a[i+1]);
	}

	cout<<"\nArray sorted in waveform: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}