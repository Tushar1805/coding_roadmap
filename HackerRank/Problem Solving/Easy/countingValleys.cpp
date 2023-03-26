// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

// Counting Valleys

#include<bits/stdc++.h>
using namespace std;

int countingValleys(int steps, string path) {
   int seaLevel = 0, count =0, temp = 0;
   for (int i=0; i<path.length(); i++) {
       if(path[i] == 'D'){
           seaLevel -= 1;
       }else{
           seaLevel += 1;
       }
       if(seaLevel< 0)
           temp = 1;
        if(temp == 1 && seaLevel == 0){
            count++;
            temp = 0;
        }
   }
   return count;
}

int main(int argc, char const *argv[])
{
	string s;
	int n, res;
	cout<<"Enter the number of steps in the path: ";
	cin>>n;
	cout<<"\nEnter the steps path: ";
	cin>>s;
	res = countingValleys(n, s);
	cout<<"\nNumber of Valleys hikers entered: "<<res;
	return 0;
}