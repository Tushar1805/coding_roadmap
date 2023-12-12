// Multidimensional Arrays can be defined in simple words as an array of arrays. Data in multidimensional arrays are stored in tabular form (in row-major order).

// The 2D array is organized as matrices which can be represented as the collection of rows and columns.

// Syntax : 
// The syntax of declaring a two-dimensional array is very much similar to that of a one-dimensional array, given as follows.

// datatype variable_name[rows][column];

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, n;
	cout<<"Enter the rows and columns of the array: ";
	cin>>m>>n;
	int a[m][n];
	cout<<"\nEnter "<<m*n<<" elements of array: ";
	for (int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; j++){
			cin>>a[i][j];
		}
	}
	cout<<"\n\nElements of array are\n";
	for (int i = 0; i < m; ++i)
	{
		cout<<"| ";
		for(int j = 0; j < n; j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<"|\n";
	}
	return 0;
}