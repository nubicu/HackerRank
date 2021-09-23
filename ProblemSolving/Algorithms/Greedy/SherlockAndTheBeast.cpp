//============================================================================
// Name        : SherlockAndTheBeast.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
//============================================================================
/* Description :
Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something
diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's
recent issues with their supercomputer, The Beast.
Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about
infecting The Beast with a virus. He also gives him a clue: an integer. Sherlock determines
the key to removing the virus is to find the largest Decent Number having that number of digits.
A Decent Number has the following properties:
1.Its digits can only be 3's and/or 5's.
2.The number of 3's it contains is divisible by 5.
3.The number of 5's it contains is divisible by 3.
4.It is the largest such number for its length.
Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out
fast. Your task is to help Sherlock find the key before The Beast is destroyed!

For example, the numbers 55533333 and 555555 are both decent numbers because there are three 5's
and five 3's in the first, and six 5's in the second. They are the largest values for those length
numbers that have proper divisibility of digit occurrences.

Function Description
Complete the decentNumber function to print the decent number for the given length, or -1 if a
decent number of that length cannot be formed.
decentNumber has the following parameter(s):
- n: the integer length of the decent number to create

Input Format : first line - integer t = the number of test cases.
The next t lines each contain an integer n, the number of digits in the number.

Constraints : 1 <= t <= 20 and 1 <= n <= 10^5

Output Format : Print the largest Decent Number having n digits; if no such number exists,
tell Sherlock by printing -1.
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Number of testcases : ";
    cin >> t;

    while(t--)
    {
        int n;
        cout << "Number of digits in the number : ";
        cin >> n;
        int x = -1, y = -1;

        for(int i = n/3; i >= 0; i--)
            if((n - 3 * i) % 5 == 0)
            {
                x = i;
                y = (n - 3 * i) / 5;
                break;
            }
            cout << "The largest Decent Number having " << n << " digits; if no such number exists, tell Sherlock by printing -1. : ";
            if(x == -1)
                cout << "-1" << endl;
            else
            {
                for(int i = 0; i < 3 * x; i++)
                    cout << "5";
                for(int i = 0; i < 5 * y; i++)
                    cout << "3";
                cout << endl;
            }
    }
    cout << "End of the program!" << endl;
    return 0;
}

/*
Sample Input
4
1
3
5
11
Sample Output
-1
555
33333
55555533333
Explanation
For n=1, there is no Decent Number having 1 digit (so we print -1).
For n=3, 555 is the only possible number. (Decent Number Property 3).
For n=5, 33333 is the only possible number. (Decent Number Property 2).
For n=11, 55555533333 is the Decent Number. All other permutations of these digits are not decent (Decent Number Property 4).
*/
