#include<bits/stdc++.h>
using namespace std;

vector<int> NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    unordered_map<int, int> mm;
    vector<int> ans;
    int count = 0;
    for(int i=0;i<n;i++){
        mm[a[i]] = 1;
    }
    for(int i=0;i<m;i++){
        if(mm[b[i]] == 1){
            count++;
            ans.push_back(b[i]);
            mm[b[i]] = 0;
        }   
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	int n, m;
	vector<int> res;
	cout<<"Enter the size of array 1 and 2 respectively: ";
	cin>>n>>m;
	int a[n];
	int b[m];
	cout<<"\nEnter the "<< n<<" elements of array 1: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the "<< m<<" elements of array 2: ";
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	res = NumberofElementsInIntersection(a, b, n , m);


	if (res.size() != 0)
	{
		cout<<"\nIntersection Array: ";
		for (int i = 0; i < res.size(); ++i)
		{
			cout<<res[i]<<" ";
		}
	}else{
		cout<<"\nNo intersection";
	}
	
	return 0;
}