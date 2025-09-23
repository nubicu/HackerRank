//============================================================================
// Name        : AccessingInheritedFunctions.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/accessing-inherited-functions/problem
//============================================================================
/* Description :
You are given three classes A, B and C. All three classes implement their own version of func.

In class A, func multiplies the value passed as a parameter by 2.
In class B, func multiplies the value passed as a parameter by 3
In class C, func multiplies the value passed as a parameter by 5
You need to modify the class D and implement the function update_val which sets D's val to new_val
by manipulating the value by only calling the func defined in classes A, B and C.

It is guaranteed that new_val has only 2, 3 and 5 as its prime factors.

Input Format : 
Implement class D's function update_val.
This function should update D's val only by calling A, B and C's func.

Constraints : 1 <= new_val <= 10000
Note: The new_val only has 2, 3 and 5 as its prime factors.
*/

#include<iostream>

using namespace std;

class A
{
private:
    int callA;
    void inc()
    {
        callA++;
    }

protected:
    void func(int & a)
    {
        a = a * 2;
        inc();
    }
public:
    A()
    {
        callA = 0;
    }
    int getA()
    {
        return callA;
    }
};

class B
{
private:
    int callB;
    void inc()
    {
        callB++;
    }
protected:
    void func(int & a)
    {
        a = a * 3;
        inc();
    }
public:
    B()
    {
        callB = 0;
    }
    int getB()
    {
        return callB;
    }
};

class C
{
private:
    int callC;
    void inc()
    {
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    C()
    {
        callC = 0;
    }
    int getC()
    {
        return callC;
    }
};

class D : public A,B,C
{

    int val;
public:
    //Initially val is 1
    D()
    {
        val = 1;
    }
    //Implement this function
    void update_val(int new_val)
    {
             int a = new_val;
             while(new_val!=0)
             {
                 if(val==a)
                    break;
                 if(new_val%2==0)
                 {
                     A::func(val);
                     new_val/=2;
                 }
                 else if(new_val%3==0)
                 {
                     B::func(val);
                     new_val/=3;
                 }
                 else if(new_val%5==0)
                 {
                     C::func(val);
                     new_val/=5;
                 }
             }
            
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}
