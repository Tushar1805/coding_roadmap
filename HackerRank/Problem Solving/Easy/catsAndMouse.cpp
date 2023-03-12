/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

// Two cats and a mouse are at various positions on a line. 
// You will be given their starting positions. 
// Your task is to determine which cat will reach the mouse first, 
// assuming the mouse does not move and the cats travel at equal speed. 
// If the cats arrive at the same time, the mouse will be allowed to move and it will escape while they fight.

// You are given q queries in the form of y, y, and z representing the 
// respective positions for cats A and B, and for mouse C. 
// Complete the function catAndMouse to return the appropriate answer to each query, 
// which will be printed on a new line.

// If cat A catches the mouse first, print Cat A.
// If cat B catches the mouse first, print Cat B.
// If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.

#include <iostream>
using namespace std;

string catAndMouse(int x, int y, int z) {
    int a_dis = abs(z - x);
    int b_dis = abs(z - y);
    if (a_dis == b_dis) 
        return "Mouse escaped";
    else if(a_dis < b_dis)
        return "Cat A reaches the mouse first";
    else
        return "Cat B reaches the mouse first";
}

int main(int argc, char const *argv[])
{
	int q;
	cout<<"Enter the number of queries: ";
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		int x, y, z;
		cout<<"\nEnter the positions of the Cat A, Cat B and Mouse: ";
		cin>>x>>y>>z;
		cout<<"\n"<<catAndMouse(x, y, z)<<endl;
	}
	return 0;
}