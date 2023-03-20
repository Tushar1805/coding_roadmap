// Roman Number to Integer

// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/0

// Given a string in roman no format (s)  your task is to convert it to an integer . 
// Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// s = V
// Output: 5
// Example 2:

// Input:
// s = III 
// Output: 3
// Your Task:
// Complete the function romanToDecimal() which takes a string as input parameter and 
// returns the equivalent decimal number. 

// Expected Time Complexity: O(|S|), |S| = length of string S.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=roman no range<=3999

#include<bits/stdc++.h>
using namespace std;

int romanToDecimal(string &s) {
    int total = 0;
    int i = s.length() - 1;
    while(i>=0){
        switch(s[i]){
            case 'I': total+=1;
                i--;
                break;
            case 'V':
                if(i-1>=0 && s[i-1] == 'I'){
                    total+=4;
                    i-=2;
                }else{
                    total+=5;
                    i--;
                }
                break;
            case 'X':
                if(i-1>=0 && s[i-1] == 'I'){
                    total+=9;
                     i-=2;
                }else{
                    total+=10;
                    i--;
                }
                break;
             case 'L':
                if(i-1>=0 && s[i-1] == 'X'){
                    total+=40;
                     i-=2;
                }else{
                    total+=50;
                    i--;
                }
                break;
             case 'C':
                if(i-1>=0 && s[i-1] == 'X'){
                    total+=90;
                     i-=2;
                }else{
                    total+=100;
                    i--;
                }
                break;
             case 'D':
                if(i-1>=0 && s[i-1] == 'C'){
                    total+=400;
                     i-=2;
                }else{
                    total+=500;
                    i--;
                }
                break;
            case 'M':
                if(i-1>=0 && s[i-1] == 'C'){
                    total+=900;
                     i-=2;
                }else{
                    total+=1000;
                    i--;
                }
                break;
            default: cout<<"No Match"<<endl;
                break;
        }
    }
    return total;
}

int main(int argc, char const *argv[])
{
	string s;
	int res;
	cout<<"Enter roman string to convert it into integer: ";
	cin>>s;
	res = romanToDecimal(s);
	cout<<"\nThe roman string "<<s<<" can represented in decimal: "<<res;
	return 0;
}