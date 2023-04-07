// Lowest Common Multiple (LCM)

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n1, n2;
	cout<<"Enter two numbers: ";
	cin>>n1>>n2;
	// int mx = max(n1, n2);
	int lcm, max;
	// for (int i = 1; i < mx; ++i)
	// {
	// 	if (((i * mx) % n1) == 0 && ((i * mx) % n2) == 0)
	// 	{
	// 		lcm = i*mx;
	// 		break;
	// 	}
	// }

	// n1>n2 ? max = n1 : max = n2; // this line can also be written as below
	max = (n1 > n2) ? n1 : n2;
	while(1){
		if ((max % n1) == 0 && (max % n2) == 0)
		{
			printf("\nLCM of %d & %d = %d", n1, n2, max);
			break;
		}
		max++;
	}
	// cout<<"LCM: "<<lcm;
	return 0;
}