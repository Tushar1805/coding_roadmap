// Factors of a numeber 

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	vector<int> factors;
	cout<<"Enter the number to find the factors of: ";
	cin>>n;

	//Iterative method
	for (int i = 1; i <= n/2; ++i)
	{
		if(n%i == 0)
			factors.push_back(i);
	}
	factors.push_back(n);
	cout<<"\nFactors of "<<n<<" are: ";
	for (int i = 0; i < factors.size(); ++i)
	{
		cout<<factors.at(i)<<" ";
	}
	return 0;
}