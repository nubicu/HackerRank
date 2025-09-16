//============================================================================
// Name        : ConditionalLoops.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/for-loop-in-c/problem
//============================================================================
/* Description :
For each integer n in the interval [a,b] (given as input) :

If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

Input Format : The first line contains an integer, a. The second line contains an integer, b.

Constraints : 1<=a<=b<=10^6

Output Format : Print the appropriate English representation,even, or odd, based on the conditions described in the 'task' section.
Note : [a,b] = {a <= x <= b} = {a, a+1, ..., b}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    for(int n = a; n <= b; n++)
    {
        if (n > 9)
        {
            if (0 == n % 2) 
            {
                cout << "even" << endl;
            }
            else
            {
                cout << "odd" << endl;
            }
        }
        else
        {
            if (1 == n)
            {
                cout << "one" << endl;
            }
            else if (2 == n)
            {
                cout << "two" << endl;
            }
            else if (3 == n)
            {
                cout << "three" << endl;
            }
            else if (4 == n)
            {
                cout << "four" << endl;
            }
            else if (5 == n)
            {
                cout << "five" << endl;
            }
            else if (6 == n)
            {
                cout << "six" << endl;
            }
            else if (7 == n)
            {
                cout << "seven" << endl;
            }
            else if (8 == n)
            {
                cout << "eight" << endl;
            }
            else
            {
                cout << "nine" << endl;
            }
        }
    }

    return 0;
}
