// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

// Sample Input 0

// 0 3 4 2
// Sample Output 0

// YES

#include<bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    int p = 0;
    do {
        x1 += v1;
        x2 += v2; 
        if (x1 == x2) {
            p = 1;
        }
    }while (x1<=100000000);
    if (p==1) {
        return "YES";
    }else{
        return "NO";
    }
}

int main(int argc, char const *argv[])
{
    int x1, x2, v1, v2;
    string result;
    cout<<"Enter starting position and jump distance for kangaroo 1: ";
    cin>>x1>>v1;
    cout<<"\nEnter starting position and jump distance for kangaroo 2: ";
    cin>>x2>>v2;
    result = kangaroo(x1, v1, x2, v2);
    cout<<"\nRESULT: "<<result;
    return 0;
}