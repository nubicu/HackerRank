//============================================================================
// Name        : DrawingBook.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/drawing-book/problem
//============================================================================
/* Description :
Brie’s Drawing teacher asks her class to open their books to a page number.
Brie can either start turning pages from the front of the book or from the back
of the book. She always turns pages one at a time. When she opens the book, page
1 is always on the right side.
When she flips page 1, she sees pages 2 and 3. Each page except the last page
will always be printed on both sides. The last page may only be printed on the
front, given the length of the book. If the book is n pages long, and she wants
to turn to page p, what is the minimum number of pages she will turn? She can
start at the beginning or the end of the book.
Given n and p, find and print the minimum number of pages Brie must turn in order
to arrive at page p.

Function Description
Complete the pageCount function to return the minimum number of pages Brie must turn.
pageCount has the following parameter(s):
- n: the number of pages in the book
- p: the page number to turn to

Input Format :
The first line contains an integer n, the number of pages in the book.
The second line contains an integer p, the page that Brie's teacher wants her to turn to.

Constraints : 1 <= n <= 10^5; 1 <= p <= n

Output Format :
Print an integer denoting the minimum number of pages Brie must turn to get to page p.
*/

#include <bits/stdc++.h>

using namespace std;

int pageCount(int n, int p) {
    int from_front = p / 2;
    int from_back = (n + 2) / 2 - from_front - 1;

    return min(from_front, from_back);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}

/*
Sample Input 0
6
2
Sample Output 0
1
Explanation 0
If Brie starts turning from page 1, she only needs to turn 1 page.
If Brie starts turning from page 6, she needs to turn 2 pages.
Because we want to print the minumum number of page turns, we print 1 as our answer.

Sample Input 1
5
4
Sample Output 1
0
Explanation 1
If Brie starts turning from page 1, she needs to turn 2 pages.
If Brie starts turning from page 5, she doesn't need to turn any pages.
Because we want to print the minimum number of page turns, we print 0 as our answer.
*/
