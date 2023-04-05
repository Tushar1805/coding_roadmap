#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

// Input to Test
// 5
// 2 3 4 5
// 4
// 5
// 4
// 2 4 6 7

class Box{
    private:
        int l, b, h;
    public:
    Box(){
        this -> l=0;this->b=0;this->h=0;
    }
    Box(int a, int b, int c){
        this -> l = a;
        this -> b = b;
         this -> h = c;
    }
    Box(Box &b1){
        this->l = b1.l;
        this->b =  b1.b ;
        this->h = b1.h; 
    }
    int getLength(){
        return this->l;
    }
    int getBreadth (){
        return this->b;
    }
    int getHeight (){
        return this->h;
    }
    long long CalculateVolume(){
        return this->l * this-> b * this-> h;
    }
    friend bool operator < (Box& b1, Box& b2)
    {
        if((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
            (b1.l == b2.l && b1.b == b2.b && b1.h <b2.h))
            return(true);
        else
            return(false);
    }

    friend ostream& operator << (ostream& s,Box& b1)
    {
        s << b1.l << " " << b1.b << " " << b1.h;
        return s;
    }
};

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}