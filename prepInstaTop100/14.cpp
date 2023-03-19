// Armstrong numbers upto n

#include<iostream>
#include<math.h>
using namespace std;

// To get the number of digits of a number
int order(int n){
	int len = 0;
	while(n!=0){
		n /= 10;
		len++;
	}
	return len;
}

int checkisarm(int n, int d){
	int arm = 0;
	while(n!=0){
		arm = arm + pow(n%10, d);
		n /= 10;
	}
	return arm;
}

int main(int argc, char const *argv[])
{
	int m, n;
	cout<<"Enter the range of the numbers(m to n): ";
	cin>>m>> n;
	cout<<"\nArmstrong numbres upto "<<n<<" are: ";
	for (int i = m; i <= n; ++i)
	{
		int d;
		// d = log10(i);
		// d++;
		d = order(i);
		int arm = checkisarm(i, d);
		if (arm == i)
		{
			cout<<arm<<" ";
		}
	}
	return 0;
}