// Perfect Square

#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter any positive integer: ";
	cin>>n;
	long long int s = sqrt(n);
	if((s * s) == n){
		cout<<"\n"<<n<<" is a perfect square of "<<s;
	}else{
		cout<<"\n"<<n<<" is not a perfect square ";
	}

	return 0;
}