// Abundant Number

// Abundant number is an number in which the sum of the proper divisors of the number is greater than the number itself.

// Ex:- Abundant number 12 having a proper divisor is 1, 2, 3, 4, 6 

// The sum of these factors is 16 it is greater than 12 
// So it is an Abundant number

// Some other abundant numbers: 

// 18, 20, 30, 70, 78, 80, 84, 90, 96, 100, 104, 108, 120

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, sum=0;
	cout<<"Enter a positive integer to check whether it is abundant or not: ";
	cin>>n;
	for (int i = 1; i <= n/2; ++i)
	{
		if(n%i == 0){
			sum+=i;
		}
	}
	if(sum>n){
		cout<<"\nThe number "<<n<<" is abundant number";
		cout << "\nThe Abundance is: " << (sum-n);
	}else{
		cout<<"\nGiven number is not abundant";
	}
	return 0;
}