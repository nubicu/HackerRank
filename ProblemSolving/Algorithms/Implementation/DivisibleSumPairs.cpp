//============================================================================
// Name        : DivisibleSumPairs.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
//============================================================================
/* Description :
You are given an array of n integers ar and a positive integer k.
Find and print the number of (i,j) pairs where i<j and ar[i] + ar[j] is divisible by k.
For example, ar = [1,2,3,4,5,6] and k=5.
Our three pairs meeting the criteria are [1,4], [2,3] and [4,6].

Function Description
Complete the divisibleSumPairs function in the editor below. It should return the integer count of
pairs meeting the criteria.
divisibleSumPairs has the following parameter(s):
n: the integer length of array ar
ar: an array of integers
k: the integer to divide the pair sum by

Input Format
The first line contains 2 space-separated integers, n and k.
The second line contains n space-separated integers describing the values of ar elements.

Constraints
2<=n<=100; 1<=k<=100; 1<=ar[i]<=100

Output Format
Print the number of (i,j) pairs where i<j and a[i] + a[j] is evenly divisible by k.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
  int nr_pairs = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if( ((ar[i] + ar[j]) % k) == 0)
      {
        nr_pairs++;
      }
    }
  }

  return nr_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
Sample Input
6 3
1 3 2 6 1 2
Sample Output
5
Explanation
Here are the 5 valid pairs when k=3:
(0,2) -> ar[0]+ar[2]=1+2=3
(0,5) -> ar[0]+ar[5]=1+2=3
(1,3) -> ar[1]+ar[3]=3+6=9
(2,4) -> ar[2]+ar[4]=2+1=3
(4,5) -> ar[4]+ar[5]=1+2=3
*/
