// https://prepinsta.com/cpp-program/cpp-program-to-find-the-reverse-of-a-number/

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
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	int org = n, rev = 0;

	// Using iterative method
	while(n!=0){
		rev = (rev * 10) + n%10;
		n /= 10;
	}
	cout<<"\nReverse of "<<org<<" is: "<<rev;

	// Using recursion
	cout <<"\n\nReverse: " << getReverse(n, rev);
	return 0;
}