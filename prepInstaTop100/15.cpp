// Fibonacci series upto nth terms

#include<bits/stdc++.h>
using namespace std;


// Using recursion
void Fib(int n){
    
    // Note : declaring static items too here
    static long long int t1 = 0, t2 = 1, nextTerm;
    
    if(n > 0)
    {    
        nextTerm = t1 + t2;
        t1 = t2;    
        t2 = nextTerm;    
    
        cout << nextTerm <<endl;    
        Fib(n-1);    
    }
    
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number upto which fibonacci series will be printed: ";
	cin>>n;
	cout<<"\nfibonacci series\n";
	int f0 = 0, f1 = 1, fib;
	cout<<f0<<endl<<f1<<endl;

	// Using iterative method
	// for (int i = 1; i <=n; ++i)
	// {
	// 	fib = f0+f1;
	// 	cout<<fib<<endl;
	// 	f0 = f1;
	// 	f1 = fib;
	// }

	// n-2 as 2 terms already printed
    Fib(n-2);

	return 0;
}