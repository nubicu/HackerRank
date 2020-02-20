//============================================================================
// Name        : TimeInWords.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/the-time-in-words/problem
//============================================================================
/* Description : 
Given the time in numerals we may convert it into words, as shown below:
5:00 -> five o' clock
5:01 -> one minute past five
5:10 -> ten minutes past five
5:15 -> quarter past five
5:30 -> half past five
5:40 -> twenty minutes to six
5:45 -> quarter to six
5:47 -> thirteen minutes to six
5:28 -> twenty eight minutes past five
At minutes=0, use o' clock. For 1<=minutes<=30, use past, and for 30<minutes use to. Note the space
between the apostrophe and clock in o' clock. Write a program which prints the time in words for the
input given in the format described.

Function Description
Complete the timeInWords function to return a time string as described.
timeInWords has the following parameter(s):
h: an integer representing hour of the day
m: an integer representing minutes after the hour

Input Format
The first line contains h, the hours portion The second line contains m, the minutes portion

Constraints: 1<=h<=12; 0<=m<60

Output Format: Print the time in words as described.
*/

#include <bits/stdc++.h>

using namespace std;

string timeToString(int n) {
    string time;

    switch (n) {
        case 0:
            time = "zero";
        case 1:
            time = "one";
        break;
        case 2:
            time = "two";
        break;
        case 3:
            time = "three";
        break;
        case 4:
            time = "four";
        break;
        case 5:
            time = "five";
        break;
        case 6:
            time = "six";
        break;
        case 7:
            time = "seven";
        break;
        case 8:
            time = "eight";
        break;
        case 9:
            time = "nine";
        break;
        case 10:
            time = "ten";
        break;
        case 11:
            time = "eleven";
        break;
        case 12:
            time = "twelve";
        break;
        case 13:
            time = "thirteen";
        break;
        case 14:
            time = "fourteen";
        break;
        case 15:
            time = "fifteen";
        break;
        case 16:
            time = "sixteen";
        break;
        case 17:
            time = "seventeen";
        break;
        case 18:
            time = "eighteen";
        break;
        case 19:
            time = "nineteen";
        break;
        case 20:
            time = "twenty";
        break;
        case 30:
            time = "thirty";
        break;
        case 40:
            time = "forty";
        break;
        case 50:
            time = "fifty";
        break;
        default:
            time = "undefined";
        break;
    }

    return time;
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
  string result = "";
  if (m == 0) {
      result = timeToString(h) + " o' clock";
  } else if (m == 1) {
      result = "one minute past " + timeToString(h);
  } else if (m == 59) {
      result = "one minute to " + timeToString(h);
  } else if (m == 15) {
      result = "quarter past " + timeToString(h);
  } else if (m == 45) {
      result = "quarter to " + timeToString(h+1);
  } else if (m == 30) {
      result = "half past " + timeToString(h);
  } else if (m > 0 && m < 30) {
      if (timeToString(m) == "undefined") {
          result = timeToString((m/10)*10) + " " +
                  timeToString(m % 10) + " minutes past " + timeToString(h);
      } else {
          result = timeToString(m) + " minutes past " + timeToString(h);
      }
  } else if (m > 30 ) {
      if (timeToString(60 - m) == "undefined") {
          result = timeToString(((60 - m) / 10) * 10) + " " +
                   timeToString((60 - m) % 10) + " minutes to " + timeToString(h+1);
      } else {
          result = timeToString(60 - m) + " minutes to " + timeToString(h+1);
      }
  }
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    cout << result << "\n";

    fout.close();

    return 0;
}

/*
Sample Input 0
5
47
Sample Output 0
thirteen minutes to six
Sample Input 1
3
00
Sample Output 1
three o' clock
Sample Input 2
7
15
Sample Output 2
quarter past seven
*/
