// 34. Find First and Last Position of Element in Sorted Array

// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& a, int x) {
    vector<int> ans;
    int n = a.size();
    int l=0, r= n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
    if(a[mid] == x){
        ans.push_back(mid);
        r = mid -1;
    }else if (a[mid] < x){
        l = mid + 1;
    }else{
        r = mid -1;
    }
    }
    
    l = 0;
    r = n-1;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == x){
            ans.push_back(mid);
            l = mid+1;
        }else if(a[mid] < x){
            l = mid+1;
        }else{
            r = mid -1;
        }
    }
    
    if(ans.size() == 0) return {-1, -1};
    sort(ans.begin(), ans.end());
    return {ans[0], ans[ans.size() -1]};
}

int main(int argc, char const *argv[])
{
    int n, x;
    vector<int> res;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> a;
    cout<<"\nEnter the "<<n<<" elements of array: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin>>value;
        a.push_back(value);
    }
    cout<<"\nEnter the number to find the first and last occurence of: ";
    cin>>x;
    res = searchRange(a, x);
    if(res[0] != -1 and res[1] != -1)
        cout<<"\nFirst occurence of "<<x<<" : "<< res[0] <<" & Last occurence of "<< x<< " : "<<res[1];
    else
        cout<<"\n"<<x<<" Not found in the array";
    return 0;
}