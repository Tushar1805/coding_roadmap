/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

// Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.

// Lily decides to share a contiguous segment of the bar selected such that:

// The length of the segment matches Ron's birth month, and,
// The sum of the integers on the squares is equal to his birth day.
// Determine how many ways she can divide the chocolate.

// Function Description

// Complete the birthday function in the editor below.

// birthday has the following parameter(s):

// int s[n]: the numbers on each of the squares of chocolate
// int d: Ron's birth day
// int m: Ron's birth month
// Returns

// int: the number of ways the bar can be divided

// Input Format

// The first line contains an integer n, the number of squares in the chocolate bar.
// The second line contains n space-separated integers s[i], the numbers on the chocolate squares where 0<= i< n.
// The third line contains two space-separated integers, d and m, Ron's birth day and his birth month.

#include<iostream>
#include <vector>
using namespace std;

int birthday(vector<int> s, int d, int m) {
    int j;
    int occurrence = 0;
   if (s.size() < m) {
       return 0;
   }else {
        for (int i=0; i<s.size(); i++) {
            int count = m;
            int bar_sum = 0;
            j = i;
            while (count != 0 && j < s.size()) {
               bar_sum += s.at(j);
               j++;
               count--;
            }
            if (bar_sum == d) {
                occurrence++;
            }
        }
        return occurrence;
   }
}

int main(int argc, char const *argv[])
{
	int n, d, m, c;
	vector<int> s;
	cout<<"Enter the number of squares in the chocolate bar: ";
	cin>>n;
	cout<<"\nEnter the numbers on the chocolate squares: ";
	for(int i =0; i<n; i++){
		int value;
		cin>>value;
		s.push_back(value);
	}
	cout<<"\nEnter Ron's birth day and his birth month: ";
	cin>>d>>m;
    c = birthday(s, d, m);
    cout<<"\nThere are "<< c<< " such ways by which chocolate can be divided: ";
	return 0;
}