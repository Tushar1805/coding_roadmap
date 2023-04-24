//! Maximum number of handshakes

//* Approach :
// For the number of handshakes to be maximum,
// every person should hand-shake with every other person in the room

// i.e. all persons present should shake hands.

// For the first person, there will be N-1 people to shake hands with
// For second person, there will be N -1 people available but as he has
// already shaken hands with the first person, there will be N-1-1 = N-2 shake-hands
// For third person, there will be N-1-1-1 = N-3, and So On…
// Therefore the total number of handshake   =   ( N – 1 + N – 2 +….+ 1 + 0 )   =   ( (N-1) * N ) / 2.

// Algorithm
// For N = 8
// handshakes  =  ( (N-1) * N ) / 2  =  ( 8 x 7 )/2  =  28
// Print Result

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int p;
	cout << "Enter the number of people: ";
	cin >> p;
	int maxHandShakes = ((p - 1) * p) / 2;
	cout << "\nMaximum possible handshakes: " << maxHandShakes;
	return 0;
}