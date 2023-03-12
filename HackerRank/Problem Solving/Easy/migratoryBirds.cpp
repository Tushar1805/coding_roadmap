/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

// Given an array of bird sightings where every element represents a bird type id, 
// determine the id of the most frequently sighted type. 
// If more than 1 type has been spotted that maximum amount, return the smallest of their ids.

// Example
// arr = [1, 1, 2, 2, 3]

// There are two each of types 1 and 2, and one sighting of type 3. 
// Pick the lower of the two types seen twice: type 1.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int migratoryBirds(vector<int> arr) {
    long long int size = arr.size();
    vector<int> count(6, 0);
    for (int i = 0; i < size; ++i)
    {
    	count.at(arr.at(i))++;
    }
    int max = count.at(1), id = 1;
    for (int i = 2; i < 6; ++i)
    {
    	if (count.at(i) > max)
    	{
    		max = count.at(i);
    		id = i;
    	}
    }
    return id;
}

int main(int argc, char const *argv[])
{
	int n, id;
	vector<int> birds;
	cout<<"Enter the total number of birds sighting: ";
	cin>>n;
	cout<<"\nEnter the id of each sighting of bird: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		birds.push_back(value);
	}
	id = migratoryBirds(birds);
	cout<<"The bird ID "<<id<<" sighted most of the times";
	return 0;
}