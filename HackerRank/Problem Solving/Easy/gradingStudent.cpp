/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

// Examples

//  grade = 84 round to 85 (85 - 84 is less than 3)
//  grade = 29 do not round (result is less than 40)
//  grade = 57 do not round (60 - 57 is 3 or higher)

// Given the initial value of grade for each of Sam's n students, write code to automate the rounding process.

// Function Description

// Complete the function gradingStudents in the editor below.

// gradingStudents has the following parameter(s):

// int grades[n]: the grades before rounding

// Returns

// int[n]: the grades after rounding as appropriate

// Input Format

// The first line contains a single integer, n , the number of students.
// Each line i of the n subsequent lines contains a single integer, grades[i].

// Sample Input 0

// 4
// 73
// 67
// 38
// 33

// Sample Output 0

// 75
// 67
// 40
// 33

vector<int> gradingStudent(vector<int> grades){
	int n = grades.size();
    for (int i = 0; i < n; i++) {
        if(grades.at(i) > 37){
            int value = grades.at(i);
            while (value % 5 != 0) {
                value += 1;
            }
            if((value - grades.at(i)) < 3){
                grades.at(i) = value;
            }
        }
    }
    return grades;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter number of student: ";
	cin>>n;
	vector<int> grades(n);
	cout<<"\nEnter grades for each student: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>grades[i];
	}
	vector<int> result = gradingStudent(grades);
	cout<<"\nRounded grades: ";
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
	return 0;
}