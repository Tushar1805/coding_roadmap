// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

// Electronic Shop

#include<iostream>
#include<vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    long long int spent = -1;
    int n = keyboards.size();
    int m = drives.size();
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            long long int sum = keyboards[i] + drives[j];
            if (sum <= b) {
                spent = max(spent, sum);
            }
        }
    }
    return spent;
}

int main(int argc, char const *argv[])
{
	int n, m, b;
	cout<<"Enter the number of keyboards and drives: ";
	cin>>n>>m;
	vector<int> keyboards, drives;
	cout<<"\nEnter "<<n<<" prices of keyboards: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		keyboards.push_back(value);
	}
	cout<<"\nEnter "<<m<<" prices of drives: ";
	for (int i = 0; i < m; ++i)
	{
		int value;
		cin>>value;
		drives.push_back(value);
	}
	cout<<"\nEnter the budget: ";
	cin>>b;

	cout<<"\nMoney Spent: "<<getMoneySpent(keyboards, drives, b);
	return 0;
}