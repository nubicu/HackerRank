//============================================================================
// Name        : OverloadOperators.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/overload-operators/problem
//============================================================================
/* Description :
You are given a class - Complex.
You need to overload operators + and << for the Complex class.
The operator + should add complex numbers according to the rules of complex addition:
(a + ib) + (c + id) = (a + c) + i(b + d)  
Overload the stream insertion operator << to add "a+ib" to the stream:
cout<<c<<endl;
The above statement should print "a+ib" followed by a newline where a = c.a and b = c.b.

Input Format :
The overloaded operator + should receive two complex numbers (a + ib and c + id) as parameters.
It must return a single complex number.

The overloaded operator << should add "a+ib" to the stream where a is the real part and
b is the imaginary part of the complex number which is then passed as a parameter to the overloaded operator.

Output Format :
As per the problem statement, for the output, print "a + ib" followed by a newline where a=c.a and b = c.b.

Constraints : 1 <= T <= 1000; 1 <= N,M <= 100; 1 <= A[i,j] <= 10
*/

#include<iostream>
using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1 = 0;
        int i = 0;
        while(s[i] != '+')
        {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while(s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            i++;
        }
        int v2 = 0;
        while(i < s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

Complex operator+ (const Complex & X, const Complex & Y)
{
    Complex Z {X.a + Y.a, X.b + Y.b};
    return Z;
}

ostream & operator<< (ostream & out, const Complex & X)
{
    if (X.b < 0)
    {
        out << X.a << "-i" << -X.b;
    }
    else if(X.b > 0)
    {
        out << X.a << "+i" << X.b;
    }
    else
    {
        out << X.a;
    }
    return out;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}
