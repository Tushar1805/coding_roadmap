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
	cout<<"\nArray elements before deletion: ";
	display(n, a);
	do{
		cout<<"\nEnter the postion from where the element is to be deleted: ";
		cin>>pos;
		if (n == 0){
		  	cout<<"\n||||| Array is empty |||||\n";
		  	break;
		}else if (pos > n || pos < 0){
			cout<<"\n\nInvalid input";
		}else{
			for (int i = pos-1; i < n; ++i)
			{
				a[i] = a[i+1];
			}
			data = a[pos-1];
			n--;
			cout<<"\nArray elements after deletion: ";
			display(n, a);
			cout<<"\nDo you want to delete an element again if Yes enter 0 press any key to exit: ";
			cin>>ch;
		}
	}while(ch == 0);
	return 0;
}