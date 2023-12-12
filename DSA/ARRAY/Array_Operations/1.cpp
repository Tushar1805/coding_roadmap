// An array is a collection of items of same data type and stores the data elements at contiguous location. It allows random access of elements.

// Array Declaration
// In C/C++
// 1. int arr[5]; //by specifying the size of array
// 2. int arr[]= {1,2,3,4,5}; //by initializing the elements
// In Java
// 1. int[]arr= new int[5]; //by specifying size
// 2. int[]arr= {1,2,3,4,5}; //by initializing the elements
// Accessing Array Elements
// Array elements are accessed using an integer called index which has value from 0 to arr.length-1

// int[]arr= [1,2,3,4,5,6,7];
// int x= arr[3] //It will give element at index 3 i.e. 4
// int y= arr[0]; //It will give element at index 0 i.e. 1
// Important Points:
// C/C++
// There is no index bound checking in C.
// In C, it is not a compiler error to initialize an array with more elements than specified size.
// In C++,  it is a compiler error to initialize an array with more elements than specified size.
// To find size of array we can use sizeof operator.
// Java

// All arrays are dynamically allocated.
// Arrays are objects in java. So size is found using arr.length.
// Direct superclass of array type is Object.
// int[] arr: (a) It just establishes that arr is an array variable. (b) No actual array actually exists. (c) It tells the compiler that arr variable will hold an array of integer type. (d) No memory is allocated. (e) Memory is allocated when we use new keyword.
// Compiler throws ArrayIndexOutOfBound Exception to indicate that array has been accessed with an illegal index.
// We can pass array to methods. A method can return an array.
// The only method that is not inherited from Object class is clone() method.

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a[10];
	printf("Enter the 10 elements of array: ");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("\nElements of array are: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}