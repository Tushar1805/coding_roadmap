// Friendly Pair or not

// Two numbers num1 & num2 are friendly pairs if the following holds true -

// (Sum of divisors of num1)/num1= (Sum of divisors of num2)/num2

#include<iostream>
using namespace std;

int getDivisorSum(int n){
	int sum =0;
	for (int i = 1; i <= n/2; ++i)
	{
		if(n%i == 0){
			sum+=i;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int n1, n2;
	cout<<"Enter the two numbers to check for the friendly pair criteria: ";
	cin>>n1>>n2;
	int sum1 = getDivisorSum(n1);
	int sum2 = getDivisorSum(n2);
	if((sum1 / n1) == (sum2 / n2)){
		cout<<"\n"<<n1<<" & "<<n2<<" are friendly pair";
	}else{
		cout<<"\nNot a friendly pair";
	}
	return 0;
}