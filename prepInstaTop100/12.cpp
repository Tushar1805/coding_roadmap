// https://prepinsta.com/cpp-program/cpp-program-to-check-whether-a-number-is-palindrome-or-not/

#include <iostream>
using namespace std;

int getReverse(int num, int rev){
    if(num == 0)
        return rev;
    
    int rem = num % 10;
    rev = rev * 10 + rem;
    
    return getReverse(num / 10, rev);
}

int main(int argc, char const *argv[])
{
	int n,rem;
	cout<<"Enter the number: ";
	cin>>n;
	int org = n, rev = 0;

	// Using iterative method
	while(n!=0){
		rem = n%10;
		rev = (rev * 10) + rem;
		n /= 10;
	}
	cout<<"\nReverse of "<<org<<" is: "<<rev;

	// Using recursion
	cout <<"\n\nReverse: " << getReverse(n, rev);

	if(org == rev)
		cout<<"\n\nWoohoo, Palindrome Number";
	else
		cout<<"\n\nHmm, not Palindrome Number";
	return 0;
}