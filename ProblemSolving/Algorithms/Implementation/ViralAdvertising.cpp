//============================================================================
// Name        : ViralAdvertising.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/strange-advertising/problem
//============================================================================
/* Description : 
HackerLand Enterprise is adopting a new viral advertising strategy. When they launch a new product,
they advertise it to exactly 5 people on social media.
On the first day, half of those  people (i.e., floor(5/2)=2) like the advertisement and each shares
it with 3 of their friends. At the beginning of the second day, floor(5/2)*3=2*3=6 people receive
the advertisement.
Each day, floor(recipients/2) of the recipients like the advertisement and will share it with 3
friends on the following day. Assuming nobody receives the advertisement twice, determine how many
people have liked the ad by the end of a given day, beginning with launch day as day .

For example, assume you want to know how many have liked the ad by the end of the 5th day.
Day Shared Liked Cumulative
1      5     2       2
2      6     3       5
3      9     4       9
4     12     6      15
5     18     9      24
The cumulative number of likes is 24.

Function Description
Complete the viralAdvertising function to return the cumulative number of people who have liked the
ad at a given time.
viralAdvertising has the following parameter(s):
n: the integer number of days

Input Format: A single integer, n, denoting a number of days.

Constraints: 1 <= n <= 50

Output Format: Print the number of people who liked the advertisement during the first n days.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
  int total = 2;
  int day[n];

  day[0] = 2;

  for (int i = 1; i < n; i++) {
   day[i] = day[i - 1] * 3 / 2;
   total += day[i];
  }

  return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

/*
Sample Input
3
Sample Output
9
Explanation
2mpeople liked the advertisement on the first day, 3 people liked the advertisement on the second
day and 4 people liked the advertisement on the third day, so the answer is 2+3+4=9.
*/
