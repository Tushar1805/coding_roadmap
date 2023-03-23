// Is perfect number or not

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, sum = 0;
	cout<<"Enter any positive number to check whether it is pefect or not: ";
	cin>>n;
	int org = n;
	for (int i = 1; i <= org/2; ++i)
	{
		if(n % i == 0){
			sum += i;
		}
	}
	if(sum == org)
		cout<<"Ureka, "<<org<<" is a Perfect Number";
	else
		cout<<org<<" Not a pefect number"; 
	return 0;
}