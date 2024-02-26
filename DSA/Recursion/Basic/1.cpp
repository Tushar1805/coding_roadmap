#include<iostream>
using namespace std;


// Demonstration of stackoverflow error
// void f(){
// 	cout<<"tushar";
// 	f();
// }

void print(int i) {
	if (i == 10) return;
	cout << i << endl;
	print(++i);
}

int main(int argc, char const *argv[])
{
	print(1);
	return 0;
}