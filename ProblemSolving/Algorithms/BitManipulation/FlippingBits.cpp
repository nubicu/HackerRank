//============================================================================
// Name        : FlippingBits.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/flipping-bits/problem
//============================================================================
/* Description : 
You will be given a list of 32 bit unsigned integers. Flip all the bits (1 -> 0
and 0 -> 1) and print the result as an unsigned integer.
For example, your decimal input n = 9(in decimal) = 1001(binar). We're working with 32 bits, so:
00000000000000000000000000001001 b = 9
11111111111111111111111111110110 b = 4 294 967 286

Function Description :
Complete the flippingBits function to return the unsigned decimal integer result.
flippingBits has the following parameter(s):
- n: an integer

Input Format :
The first line of the input contains q, the number of queries.
Each of the next q lines contain an integer, n, to process.

Constraints : 1 <= q <= 100; 0 <= n < 2^32

Output Format
Output one line per element from the list with the decimal value of the resulting unsigned integer.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    return (n ^ 0xFFFFFFFF);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        cout << result << "\n";
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

/*
Sample Input 0
3
2147483647
1
0
Sample Output 0
2147483648
4294967294
4294967295
Explanation 0
01111111111111111111111111111111 b = 2 147 483 647
10000000000000000000000000000000 b = 2 147 483 648
00000000000000000000000000000001 b =             1
11111111111111111111111111111110 b = 4 294 967 294
00000000000000000000000000000000 b =             0
11111111111111111111111111111111 b = 4 294 967 295

Sample Input 1
2
4
123456
Sample Output 1
4294967291
4294843839
Explanation 1
00000000000000000000000000000100 b =             4
11111111111111111111111111111011 b = 4 294 967 291
000000000000‭00011110001001000000‬ b =       123 456
11111111111111100001110110111111 b = 4 294 843 839

Sample Input 2

2
802743475
35601423
Sample Output 2
3492223820
4259365872
Explanation 2
00101111110110001110010010110011 b =   802 743 475
11010000001001110001101101001100 b = 3 492 223 820
*/