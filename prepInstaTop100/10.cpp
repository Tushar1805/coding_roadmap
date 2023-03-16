// https://prepinsta.com/cpp-program/cpp-program-to-find-the-sum-of-digits-of-a-number/

#include<iostream>
using namespace std;

int getSum(string num)
{
    int sum = 0;
 
    // Traverse through the whole string(char array)
    for (int i = 0; i < num.length(); i++) 
    {
        // Ascii value pf numbers start from 48
        // subtracting 48 will give us value in int
        sum = sum + num[i] - 48;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
	int n,sum = 0;
	cout<<"Enter a number: ";
	cin>>n;
	int org = n;
	while(n!=0){
		sum += n%10;
		n /= 10;
	}
	cout<<"\nSum of the digits of "<<org<<": "<<sum;

	string num = "9876543219876543219876";

    // can also use below
    // int len = sizeof(num)/sizeof(num[0]);
    
    cout<< "\n\nSum: " << getSum(num);

	return 0;
}