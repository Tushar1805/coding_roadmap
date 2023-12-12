#include<iostream>
using namespace std;

void display(int n, int a[]){
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	int n, pos, data, ch;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	cout<<"\nArray elements before insertion: ";
	display(n, a);
	do{
		cout<<"\nEnter the postion and data to be entered in the array: ";
		cin>>pos>>data;
		if (pos > n || pos < 0)
		{
			cout<<"\n\nInvalid input";
		}else{
			for (int i = n; i >= pos-1; --i)
			{
				a[i+1] = a[i];
			}
			a[pos-1] = data;
			n++;
			cout<<"\nArray elements after insertion: ";
			display(n, a);
			cout<<"\nDo you want to insert an element again if Yes enter 0 press any key to exit: ";
			cin>>ch;
		}
	}while(ch == 0);
	return 0;
}