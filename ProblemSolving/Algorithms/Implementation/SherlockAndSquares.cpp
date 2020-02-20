//============================================================================
// Name        : SherlockAndSquares.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/sherlock-and-squares/problem
//============================================================================
/* Description : 
Watson likes to challenge Sherlock's math ability. He will provide a starting and ending value describing a range of integers.
Sherlock must determine the number of square integers within that range, inclusive of the endpoints.
Note: A square integer is an integer which is the square of an integer, e.g 1,4,9,16,25 ...
Input Format
The first line contains , the number of test cases.
Each of the next  lines contains two space-separated integers denoting  and , the starting and ending integers in the ranges.
Constraints : 1<=t<=100 and 1<=a<=b<=10^9
Output Format
For each test case, print the number of square integers in the range on a new line.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int squares(int a, int b) {
    int returnResult = 0;
    returnResult = ((int)(floor(sqrt((double)b))-ceil(sqrt((double)a))+1));
    return returnResult;
}

int main()
{
    int t;
    cout << "Number of test cases is : ";
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int b;
        cout << "Values for a and b : ";
        cin >> a >> b;
        int result = squares(a, b);
        cout << "Number of square integers in the range : " << result << endl;
    }
    return 0;
}
