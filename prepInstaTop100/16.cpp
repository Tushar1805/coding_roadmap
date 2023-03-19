// Nth term in fibonacci series

#include<bits/stdc++.h>
using namespace std;

// Using recursion
int F(int n){
	if (n<=1)
		return n;
	return F(n-1) + F(n-2);	
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the term you want to find the in the fibonacci series: ";
	cin>>n;
	int t1  = 0, t2= 1, nextTerm;
	for (int i = 1; i < n; ++i)
	{
		nextTerm = t1+t2;
		t1 = t2;
		t2 = nextTerm;
	}
	cout<<endl<<n<<"th term of fibonacci series is: "<<nextTerm;
	cout<<endl<<n<<"th term of fibonacci series is: "<<F(n);
	return 0;
}