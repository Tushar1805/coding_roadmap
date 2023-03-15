// https://prepinsta.com/c-program/prime-number-or-not-in-c-programming/

#include <iostream>
using namespace std;

int checkPrime(int n, int i)
{
    // we check if i is divisor of n or not here
    
    // 0, 1 & neg. nos are not prime
    if (n < 2)
        return 0;
    
    // if this satisfies then its prime as we
    // have completed recursion from 2 to n
    if (i == n)
        return 1;

    // Base cases
    if (n % i == 0)
        return 0;
       
    // none of above condition matches
    // keep checking for next divisor in i+1 recursion call
    i += 1;
    
    return checkPrime(n, i);
}

int main(int argc, char const *argv[])
{

	// For printing all prime numbers in range

	// int r;
	// cout<<"Enter range: ";
	// cin>>r;
	// for (int j = 2; j < r; ++j)
	// {
	// 	int check = 0;
	// 	if (j < 2)
	// 		check = 1;
	// 	else{
	// 		for (int i = j/2; i > 1; --i)
	// 		{
	// 			if(j%i == 0 && j!=i){
	// 				check = 1;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	if(!check)
	// 		cout<<endl<<j;
	// }

	// Using n/2 iterations

	int n, check = 0;
	cout<<"Enter a number: ";
	cin>>n;
	if (n < 2)
		check = 1;
	else{
		for (int i = n/2; i > 1; --i)
		{
			if(n%i == 0){
				check = 1;
				break;
			}
		}
	}
	if(check)
		cout<<endl<<"The number "<<n<<" is not a prime number";
	else
		cout<<endl<<"The number "<<n<<" is a prime number";

	// Using basic recursion
	cout<< "\n// Using basic recursion";

	if(checkPrime(n, 2))
        printf("\n%d is Prime",n);
    else
        printf("\n%d is Not Prime",n);
	return 0;
}
