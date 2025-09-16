//============================================================================
// Name        : BoxIt.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/box-it/problem
//============================================================================
/* Description :
Design a class named Box whose dimensions are integers and private to the class. 
The dimensions are labelled: length l, breadth b, and height h.

The default constructor of the class should initialize l, b, and h to 0.

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l, b and h to
length, breadth and height.

The copy constructor Box(Box B) should set l, b and h to B's l, b and h, respectively.

Apart from the above, the class should have 4 functions:
int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box

Overload the operator < for the class Box.
Box A < Box B if:
A.l < B.l
A.b < B.b and A.l == B.l
A.h < B.h and A.b == B.b and A.l == B.l
Overload operator << for the class Box().

If B is an object of class Box cout << B should print B.l, B.b and B.h on a single line separated by spaces.

Constraints : 0 <= l, b, h <= 10^5

Note : Two boxes being compared using the  operator will not have all three dimensions equal.
*/

#include <bits/stdc++.h>
using namespace std;

class Box
{
private:
    int length, breadth, height;
public:
    // Constructors    
    Box() : length(0), breadth(0), height(0) {}
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}
    Box(const Box& box) : length(box.length), breadth(box.breadth), height(box.height) {}

    // Getter functions
    int getLength() { return length; }
    int getBreadth() { return breadth; }
    int getHeight() { return height; }

    // Calculate volume
    long long CalculateVolume() { return static_cast<long long>(length) * breadth * height; }

    // Operator overloading <
    bool operator<(const Box& b) {
        if (length < b.length)
            return true;
        else if (length == b.length && breadth < b.breadth)
            return true;
        else if (length == b.length && breadth == b.breadth && height < b.height)
            return true;
        else
            return false;
    }

    // Operator overloading <<
    friend ostream& operator<<(ostream& out, const Box& B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
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
