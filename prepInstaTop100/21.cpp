// Strong number or not

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	long long int fact, strong = 0;
	cout<<"Enter any positive integer: ";
	cin>>n;
	int dup = n;
	while(dup!=0){
		fact = 1;
		for (int i = dup%10; i >= 1; --i)
		{
			fact *= i;
		}
		dup = dup / 10;
		strong += fact;
	}

	if(strong == n)
		cout<<"The given number "<<n<<" is a strong number";
	else
		cout<<n<<" not a strong number";
	return 0;
}