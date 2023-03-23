// Finding prime factors of a number

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter any positive number to find the prime factors of it: ";
	cin>>n;
	int org = n;
	cout<<"\nPrime Factors of "<<n<<" are: ";
	for (int i = 2; i < org/2; ++i)
	{
		while(n % i == 0){
			cout<<i<<" ";
			n = n/i;
		}
	}
	if (n > 2) 
        cout << n << " "; 
	return 0;
}