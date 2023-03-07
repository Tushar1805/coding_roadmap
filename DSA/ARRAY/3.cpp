
// There are many sorting techniques to sort the array
// like quick sort, merge sort, bubble sort, and insertion sort them is scripted below.

// Example :

// Size : 5
// Elements of array : 5 7 2 1 6
// Array after sorting : 1 2 5 6 7 

#include <iostream>
#include <conio.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

class sort
{
	int n;
	int *a;

public:
	sort(int m){
		n = m;
		a = new int[m]; 
	}

	void display(){
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
	}

	void takeInput(){
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
	}

	// 1
	void bubbleSort(){
		auto start = chrono::steady_clock::now();

		for (int i = 0; i < n-1; ++i)
		{
			for (int j = 0; j < n-i-1; ++j)
			{
				if (a[j] > a[j+1])
				{
					// int temp = a[j];
					// a[j] = a[j+1];
					// a[j+1] = temp;
					swap(a[j], a[j+1]);
				}
			}
		}
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nWorst Case Time Complexity: O(n^2)";
		cout <<"\nBest Case Time Complexity: O(n^2)";
		cout <<"\nSpace Complexity: O(1)\n";
	}

	// 2
	void revisedBubbleSort(){
		auto start = chrono::steady_clock::now();

		for (int i = 0; i < n-1; ++i)
		{
			bool swapped = false;
			for (int j = 0; j < n-i-1; ++j)
			{
				if (a[j] > a[j+1])
				{
					// int temp = a[j];
					// a[j] = a[j+1];
					// a[j+1] = temp;
					swap(a[j], a[j+1]);
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nWorst Case Time Complexity: O(n^2)";
		cout <<"\nBest Case Time Complexity: O(n)";
		cout <<"\nSpace Complexity: O(1)\n";
	}

	// 3
	void selectionSort(){
		auto start = chrono::steady_clock::now();
		int min_index;
		for (int i = 0; i < n-1; ++i)
		{
			min_index = i;
			for (int j = i+1; j < n; ++j)
			{
				if (a[j] < a[min_index])
					min_index = j;
			}
			if (min_index != i){
				// int temp = a[min_index];
				// a[min_index] = a[i];
				// a[i] = temp;
				swap(a[min_index], a[i]);
			}
		}
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nWorst Case Time Complexity: O(n^2)";
		cout <<"\nBest Case Time Complexity: O(n^2)";
		cout <<"\nSpace Complexity: O(1)\n";
	}

	// 4
	void insertionSort(){
		auto start = chrono::steady_clock::now();

		int key, j;
		for (int i = 0; i < n; ++i)
		{
			key = a[i];
			j = i-1;
			while(j>=0 && a[j] > key){
				a[j+1] = a[j];
				j = j-1;
			}
			a[j+1] = key;
		}

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nWorst Case Time Complexity: O(n^2)";
		cout <<"\nBest Case Time Complexity: O(n)";
		cout <<"\nSpace Complexity (Aux.): O(1)\n";
	}

	// 5
	void quickSort(){
		auto start = chrono::steady_clock::now();

		quickSortMain(a, 0, n-1);

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nWorst Case Time Complexity: O(n^2)";
		cout <<"\nBest Case Time Complexity: O(n log n)";
		cout <<"\nSpace Complexity: O(1)";
		cout <<"\nAuxiliary Space Complexity: O(log n)\n";
	} 

	// 6
	void mergeSort(){
		auto start = chrono::steady_clock::now();

		mergeSortMain(a, 0, n-1);

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nTime Complexity (Worst and Best): O(n log n)";
		cout <<"\nSpace Complexity: O(n)\n";
	}

	// 7
	void countSort(){
		auto start = chrono::steady_clock::now();

		cout<<"Entered into the count sort\n";

		int max;
		int b[n];

		// Here we find the largest item in the array
		max = getMax(a, n);

		int count[max];
		// Initialize the count for each element in array to 0
		for (int i = 0; i <= max; ++i)
		{
			count[i] = 0;
		}

		// For each element we store the count
		for (int i = 0; i < n; ++i)
		{
			count[a[i]]++;
		}

		// Store the cummulative count of each array
		for (int i = 1; i <= max; ++i)
		{
			count[i] = count[i] + count[i-1];
		}

		// Search the index of each element of the actual array in count array, and
		// place the elements in output array
		for (int i = n-1; i >= 0; --i)
		{
			b[--count[a[i]]] = a[i];
		}

		// Transfer the sorted items into actual array
		for (int i = 0; i < n; ++i)
		{
			a[i] = b[i];
		}

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nTime Complexity: O(n+k)\nWhere, \n\tn - no. of elements of array\n\tk - range of distinct elements in array (or maximum number in the array)\n";
		cout <<"\nSpace Complexity: O(n+k)\n";
	}

	// 8
	void radixSort(){
		auto start = chrono::steady_clock::now();

		radixSortMain(a, n);

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		cout <<"\nTime Complexity: O(d*(n+k))\nWhere, \n\td - no. of digits of max number\n\tn - no. of elements of array\n\tk - range of distinct elements in array (or maximum number in the array)\n";
		cout <<"\nSpace Complexity: O(n+k)\n";
	}

	// 9
	void bucketSort(){
		auto start = chrono::steady_clock::now();

		// code here

		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		cout <<"\nTime Taken: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
		// cout <<"\nTime Complexity: O(d*(n+k))\nWhere, \n\td - no. of digits of max number\n\tn - no. of elements of array\n\tk - range of distinct elements in array (or maximum number in the array)\n";
		// cout <<"\nSpace Complexity: O(n+k)\n";
	}

private:
	// void swap(int &a, int &b){
	// 	cout<<"a: "<< a<< endl;
	// 		int temp = a;
	// 		a = b;
	// 		b = temp;
	// }

	int getMax(int a[], int n){
		int max = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (a[i]>max)
			{
				max = a[i];
			}
		}
		return max;
	}

	// 5
	int partition(int a[], int lb, int ub){
		int pivot = a[lb];
		int start = lb;
		int end = ub;
		while(start<=end){
			while (a[start] <= pivot)
			{
				start++;
			}
			while(a[end] > pivot){
				end--;
			}
			if (start < end)
			{
				swap(a[start], a[end]);
			}
		}
		swap(a[lb], a[end]);
		return end;
	}

	void quickSortMain(int a[], int lb, int ub){
		int loc;		
		if (lb<=ub){
			loc = partition(a, lb, ub);
			quickSortMain(a, lb, loc-1);
			quickSortMain(a, loc+1, ub);
		}
	}

	// 6

	void mergeSortMain(int a[], int lb, int ub){
		int mid;
		if (lb<ub)
		{
			mid = (lb+ub)/2;
			mergeSortMain(a, lb, mid);
			mergeSortMain(a, mid+1, ub);
			merge(a, lb, mid, ub);
		}
	}

	void merge(int a[], int lb, int mid, int ub){
		int i = lb, j = mid+1, k = lb, p, b[ub+1];
		while(i <= mid && j <= ub){
			if (a[i] <= a[j])
			{
				b[k] = a[i];
				i++;
			}else{
				b[k] = a[j];
				j++;
			}
			k++;
		}
		if(i>mid){
			while(j<=ub){
				b[k] = a[j];
				k++;
				j++;
			}
		}else{
			while(i<=mid){
				b[k] = a[i];
				i++;
				k++;
			}
		}
		p = lb;
		while(p<=ub){
			a[p] = b[p];
			p++;
		}
	}

	// 8
	void radixSortMain(int a[], int n){
		int max = getMax(a, n);
		for (int pos = 1; (max/pos) > 0; pos *= 10)
		{
			rdCountSort(a, n, pos);
		}
	}

	void rdCountSort(int a[], int n, int pos){
		int count[n], b[n];
		// Initialize the count for each element in array to 0
		for (int i = 0; i < n; ++i)
		{
			count[i] = 0;
		}

		// For each element we store the count
		for (int i = 0; i < n; ++i)
		{
			count[(a[i]/pos)%10]++;
		}

		// Store the cummulative count of each array
		for (int i = 1; i <= n; ++i)
		{
			count[i] += count[i-1];
		}

		// Search the index of each element of the actual array in count array, and
		// place the elements in output array
		for (int i = n-1; i >= 0; --i)
		{
			b[--count[(a[i]/pos)%10]] = a[i];
		}

		// Transfer the sorted items into actual array
		for (int i = 0; i < n; ++i)
		{
			a[i] = b[i];
		}
	}
};

int main(int argc, char const *argv[])
{
	int n, ch, c;
	do{
		cout<<"Enter the size of array: ";
		cin>>n;
		sort s(n);
		cout<<"\nEnter "<<n<<" elements of array: ";
		s.takeInput();
		cout<<"\nArray elements before sorting: ";
		s.display();
		cout<<"\n\nEnter 1 to perform bubble sort";
		cout<<"\nEnter 2 to perform revised bubble sort";
		cout<<"\nEnter 3 to perform selection sort";
		cout<<"\nEnter 4 to perform insertion sort";
		cout<<"\nEnter 5 to perform quick sort";
		cout<<"\nEnter 6 to perform merge sort";
		cout<<"\nEnter 7 to perform counting sort";
		cout<<"\nEnter 8 to perform radix sort";
		// cout<<"\nEnter 9 to perform bucket sort";
		cout<<"\nEnter your choice to perform the sorting algorithm: ";
		cin>>ch;
		switch(ch){
			case 1:
				s.bubbleSort();
				cout<<"Array Elements after sorting: ";
				s.display();
				break;
			case 2:
				s.revisedBubbleSort();
				cout<<"Array Elements after sorting: ";
				s.display();
				break;
			case 3:
				s.selectionSort();
				cout<<"Array Elements after sorting: ";
				s.display();
				break;
			case 4: 
				s.insertionSort();
				cout<<"Array Elements after sorting: ";
				s.display();
				break;
		 	case 5:
		 		s.quickSort();
		 		cout<<"Array Elements after sorting: ";
		 		s.display();
		 		break;
		 	case 6: 
		 		s.mergeSort();
		 		cout<<"Array Elements after sorting: ";
		 		s.display();
		 		break;
		 	case 7: 
		 		s.countSort();
		 		cout<<"Array Elements after sorting: ";
		 		s.display();
		 		break;
		 	case 8: 
		 		s.radixSort();
		 		cout<<"Array Elements after sorting: ";
		 		s.display();
		 		break;
		 	// case 9: 
		 	// 	s.bucketSort();
		 	// 	cout<<"Array Elements after sorting: ";
		 	// 	s.display();
		 	// 	break;
		 	default:
		 		cout<<"\nInvalid choice\n";
		 		break;
		}
		cout<<"\nDo you want to continue? 1 for Yes / any key to exit: ";
		cin>>c;
	}while(c==1);
	// getch();
	return 0;
}