//! 39. Quadrants in which a given coordinate lies

#include<iostream>
using namespace std;

void checkQuadrant(int x, int y) {
	if (x > 0 && y > 0)
	{
		cout << "\n" << x << " & " << y << " lies in the first quadrant";
	} else if (x < 0 && y < 0) {
		cout << "\n" << x << " & " << y << " lies in the third quadrant";
	} else if (x > 0 && y < 0) {
		cout << "\n" << x << " & " << y << " lies in the fourth quadrant";
	} else if (x < 0 && y > 0) {
		cout << "\n" << x << " & " << y << " lies in the second quadrant";
	} else if (x == 0 && y == 0) {
		cout << "\n" << "Points lies on the origin";
	} else if (x != 0 && y == 0) {
		cout << "\n" << "Points lies on the x-axix";
	} else {
		cout << "\n" << "Points lies on the y-axix";
	}
}

int main(int argc, char const *argv[])
{
	int x, y;
	cout << "Enter the value of x and y to check in which quadrant they lie: ";
	cin >> x >> y;
	checkQuadrant(x, y);
	return 0;
}