/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true


// Maria plays college basketball and wants to go pro. Each season she maintains a record of her play. 
// She tabulates the number of times she breaks her season record for most points and least points in a game. 
// Points scored in the first game establish her record for the season, and she begins counting from there.

// Example: scores [12,24,10,24]

//                                      Count
//     Game  Score  Minimum  Maximum   Min Max
//      0      12     12       12       0   0
//      1      24     12       24       0   1
//      2      10     10       24       1   1
//      3      24     10       24       1   1

// Given the scores for a season, determine the number of times Maria breaks 
// her records for most and least points scored during the season.

// Function Description

// Complete the breakingRecords function in the editor below.

// breakingRecords has the following parameter(s):

// int scores[n]: points scored per game

#include<iostream>
#include <vector>
using namespace std;

vector<int> breakingRecords(vector<int> scores) {
  vector<int> record (2,0);
  int min = scores.at(0);
  int max = scores.at(0);
  for (int i=1; i<scores.size(); i++) {
      if (scores.at(i)<min) {
          min = scores.at(i);
          record.at(1)++;
      }
      if (scores.at(i) > max) {
          max = scores.at(i);
          record.at(0)++;
      }
  }
  return record;
}


int main(int argc, char const *argv[])
{
	int n;
	vector<int> result;
	cout<<"Enter the number of games played: ";
	cin>>n;
	vector<int> scores;
	cout<<"\nEnter the scores of "<<n<<" games: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		scores.push_back(value);
	}
	result = breakingRecords(scores);
	cout<<"\nThe max and min record breaking count is: "<<result.at(0)<< " & "<< result.at(1);

	return 0;
}

