//============================================================================
// Name        : BitArray.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/bitset-1/problem
//============================================================================
/* Description: 
You are given four integers: N, S, P, Q.
You will use them in order to create the sequence a with the following pseudo-code.
a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
Your task is to calculate the number of distinct integers in the sequence a.

Input Format: Four space separated integers on a single line, N, S, P, and Q respectively.

Constraints: 1 <= N <= 108; 0 <= S, P, Q <=231

Output Format: Each line of output contains 64 binary characters (i.e., 0‘s and 1‘s).
Each character represents one value in the range.
The first character corresponds to the first value in the range.
The last character corresponds to the last value in the range.
The character is 1 if the value in the range matches X; otherwise, the character is 0.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long n, s, p, q, r = 0, ans = 0, returned, v;

    cin >> n >> s >> p >> q;
    unsigned long long i, a0 = s, a = s, ap = 0, k = 0;

    v = pow(2, 31);

    for (i = 0; i < n; i++)
    {
        a = (a * p + q);
        a = a % v;

        if ((a == a0 || a == ap) && i != 0)
        {
            k = i + 1;
            break;
        }
        ap = a;
    }

    if (i == n) k = i;

    cout << k << endl;

    return 0;
}
