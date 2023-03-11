
/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

// Output Format

// Print two integers on two different lines:

// The first integer: the number of apples that fall on Sam's house.
// The second integer: the number of oranges that fall on Sam's house.
// Sample Input 0

// 7 11
// 5 15
// 3 2
// -2 2 1
// 5 -6
// Sample Output 0

// 1
// 1

#include<bits/stdc++.h>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int noApp = 0, noOrg = 0;
    int m = apples.size();
    int n = oranges.size();
    for (int i = 0; i<m; i++) {
        if((a+apples.at(i))>= s && (a+apples.at(i))<= t){
            noApp++;
        }
    }
    for (int i = 0; i<n; i++) {
        if((b+oranges.at(i))>= s && (b+oranges.at(i))<= t){
            noOrg++;
        }
    }
    cout<<"\nNumber of Apples fallen on Sam's house: "<<noApp<<endl;
    cout<<"Number of oranges fallen on Sam's house: "<<noOrg;
}

int main(int argc, char const *argv[])
{
	int s, t, a, b, m, n;
	cout<<"Enter the starting and ending point of Sam's house: ";
	cin>>s>>t;
	cout<<"\nEnter the location of apple and orange tree: ";
	cin>>a>>b;
	cout<<"\nEnter number of apples and number of oranges landed: ";
	cin>>m>>n;
	vector<int> apples(m);
	vector<int> oranges(n);
	cout<<"\nEnter "<<m<<" respective distances that each apple falls from point a: ";
	for (int i = 0; i < m; ++i)
	{
		cin>>apples[i];
	}
	cout<<"\nEnter "<<n<<" respective distances that each apple falls from point b: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>oranges[i];
	}
	countApplesAndOranges(s,t,a,b, apples, oranges);

	return 0;
}
