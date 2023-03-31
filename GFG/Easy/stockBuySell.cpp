// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1?page=2&category[]=Arrays&sortBy=submissions

// Stock buy and sell

// The cost of stock on each day is given in an array A[] of size N. 
// Find all the segments of days on which you buy and sell the stock 
// so that in between those days your profit is maximum.

// Note: Since there can be multiple solutions, 
// the driver code will print 1 if your answer is correct, otherwise, it will return 0. 
// In case there's no profit the driver code will print the string "No Profit" for a correct solution.

// Example 1:

// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will 
// give us maximum profit. Now, we buy 
// stock on day 4 and sell it on day 6.
// Example 2:

// Input:
// N = 5
// A[] = {4,2,2,2,4}
// Output:
// 1
// Explanation:
// There are multiple possible solutions.
// one of them is (3 4)
// We can buy stock on day 3,
// and sell it on 4th day, which will 
// give us maximum profit.

// Your Task:
// The task is to complete the function stockBuySell() 
// which takes an array A[] and N as input parameters and finds the days of buying and selling stock. 
// The function must return a 2D list of integers containing all the buy-sell pairs 
// i.e. first value of pair will represent the day on which you buy the stock 
// and second value represent the day on which you sell that stock. If there is No Profit, 
// return an empty list.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 2 ≤ N ≤ 106
// 0 ≤ A[i] ≤ 106

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > stockBuySell(vector<int> A, int n){
    vector<vector<int>> ans;
    int buy, sell;
    int i = 0;
    while(i < n-1){
        vector<int> a;
        while((i< n-1) && (A[i]>=A[i+1]))
            i++;
        if(i==n-1)
            break;
        
        a.push_back(i);
        cout<<i<<endl;
        i++;
        
        while((i<n) && (A[i]>=A[i-1]))
            i++;
        a.push_back(i-1);
        cout<<i<<endl;
        ans.push_back(a);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<int> price;
    vector<vector<int>> ans;
    cout<<"Enter the number of days stock traded on: ";
    cin>>n;
    cout<<"\nEnter the price of stock on each day: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin>>value;
        price.push_back(value);
    }
    ans = stockBuySell(price, n);
    cout<<"\nBuy and sell pairs on which the stock can be traded: \n";
    for (int i = 0; i < ans.size(); ++i)
    {
        int buy, sell;
        buy = price[ans[i][0]];
        sell = price[ans[i][1]];
        cout<<"Buy: "<<buy<<" Sell: "<<sell<<endl;
    }
    return 0;
}