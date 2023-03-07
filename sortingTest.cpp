#include<iostream>
using namespace std;

void display(int a[], int size){
	for (int i = 0; i < size; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void swapp(int &a, int &b){
	static int c = 1;
	cout<<"a"<<c<<": "<<a<<endl;
	int temp = a;
	a = b;
	b = temp;
	c++;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter size of array: ";
	cin>> n;
	int a[n];
	cout<<"Enter the "<<n<<" elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	cout<<"Array elements before sorting: ";
	display(a, n);

	// // Bubble Sort
	// for (int i = 0; i < n - 1; ++i)
	// {
	// 	for (int j = 0; j < n-i-1; ++j)
	// 	{
	// 		if (a[j]>a[j+1])
	// 		{
	// 			swapp(a[j], a[j+1]);
	// 		}
	// 	}
	// }

	// // Revised Bubble sort
	// for (int i = 0; i < n - 1; ++i)
	// {
	// 	bool swapped = false;
	// 	for (int j = 0; j < n-i-1; ++j)
	// 	{
	// 		if (a[j]>a[j+1])
	// 		{
	// 			swapp(a[j], a[j+1]);
	// 			swapped = true;
	// 		}
	// 	}
	// 	if(!swapped)
	// 		break;
	// }

	// // Selection Sort
	// for (int i = 0; i < n-1; ++i)
	// {
	// 	int min_index = i;
	// 	for (int j = i+1; j < n; ++j)
	// 	 {
	// 	 	if (a[min_index]>a[j])
	// 	 	{
	// 	 		min_index = j;
	// 	 	}
	// 	 } 
	// 	 if(min_index != i)
	// 	 	swapp(a[min_index], a[i]);
	// }

	// // Insertion Sort
	// for (int i = 0; i < n; ++i)
	// {
	// 	int key = a[i];
	// 	int j = i - 1;
	// 	while (j>=0 && key < a[j])
	// 	{
	// 		a[j+1] = a[j];
	// 		j = j - 1;
	// 	}
	// 	a[j+1] = key;
	// }

	cout<<"Array elements after sorting: ";
	display(a, n);

	return 0;
}