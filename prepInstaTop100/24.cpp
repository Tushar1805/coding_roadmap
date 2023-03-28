// Automorphic Number

// An Automorphic number is a special number, whose’s square ends with the same digits as the number itself

// Test Case: 
// Input: 376
// output: Num: 376, Square: 141376 - is Automorphic

#include<iostream>
using namespace std;

isAutomorphic(int n, int square){
	while(n != 0)
    {
        // means not automorphic number
        if(n % 10 != square % 10){
            return 0;
        }        
        // reduce down numbers
        n /= 10;
        square /= 10;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter a number to check automorpic or not: ";
	cin>>n;
	long long int square = n*n;
	int res;
	res = isAutomorphic(n, square);
	if(res == 1)
		cout << "\nNum: "<< n << ", Square: " << square << " - is Automorphic";
	else
		cout << "\nNum: "<< n << ", Square: " << square << " - is not Automorphic";
	return 0;
}