// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
    double t;
    double sum = 0;
    for (int i = 0; i<bill.size(); i++) {
        if(i != k){
            sum = sum+bill[i];
        }
    }
    t = sum / 2;
    if(t == b)
       // cout<<"Bon Appetit";
        cout<<"\nAmount equally distributed";
    else 
        (t>b)?cout<<"\nAnna has to pay: "<<t-b : cout<<"\nBrian will have to return: "<<b-t;
}

int main(int argc, char const *argv[])
{
    int n, k, b;
    vector<int> bill;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"\nEnter the cost of each item consumed: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin>>value;
        bill.push_back(value);
    }
    cout<<"\nEnter the 0-based index of item which is not consumed by Anna: ";
    cin>>k;
    cout<<"\nEnter the amount Anna contributed to the bill: ";
    cin>>b;
    bonAppetit(bill, k, b);
    return 0;
}
