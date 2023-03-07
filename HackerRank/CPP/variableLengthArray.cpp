/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true

// Sample Input

// 2 2
// 3 1 5 4
// 5 1 2 8 9 3
// 0 1
// 1 3
// Sample Output

// 5
// 9

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, q, i, j, m, o;
	cout<<"Enter the count for number of array and queries: ";
    cin>>n>>q;
    vector<vector<int>> input;
    vector<int> output;
    
    for (i = 0; i<n; i++) {
        int c;
        vector<int> a;
        cout<<"\nEnter how many elements are there in array "<<i+1<<": ";
        cin>>c;
        cout<<"\nEnter "<<c<<" elements of array "<<i+1<<": ";
        for (j=0; j<c; j++) {
            int value;
            cin>>value;
            a.push_back(value);
        }
        input.push_back(a);
    } 
    
    for (int k=0; k<q; k++) {
    	cout<<"\nEnter the value for array number and index inside the array: ";
        cin>>m>>o;
        output.push_back(input[m].at(o));
    }

    for(int i=0;i<n;i++){
    	cout<<"Query "<<i+1<<": "<<output.at(i)<<endl;
    }
	return 0;
}


