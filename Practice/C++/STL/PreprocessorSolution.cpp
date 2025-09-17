//============================================================================
// Name        : PreprocessorSolution.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/preprocessor-solution/problem
//============================================================================
/* Description :
You're spending your afternoon at a local school, teaching kids how to code. You give them a simple task:
find the difference between the maximum and minimum values in an array of integers.
After a few hours, they came up with some promising source code. Unfortunately, it doesn't compile!
Since you don't want to discourage them, you decide to make their code work without modifying it by adding preprocessor macros.
Review the locked stub code in your editor and add the preprocessor macros necessary to make the code work.

Input Format :
The first line contains an integer, N, denoting the size of the array.
The second line contains N space-separated integers, x1, x2, ..., xn describing the elements in the array.

Output Format :
You are not responsible for printing any output to stdout.
Once the necessary preprocessor macros are written, the locked code in your editor will print a line that says Result = Z,
where Z is the difference between the maximum and minimum values in the array.

Constraints : 1 <= N <= 10^3; -10^8 <= Xi <= 10^8
*/

#define toStr(x) #x
#define io(v) cin >> v
#define INF 100000000
#define foreach(v, i) for(int i = 0; i < v.size(); i++)
#define FUNCTION(name, op) void name(int& a, int b) { if (b op a) a = b; }


#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;
}
