//============================================================================
// Name        : LonelyInteger.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/lonely-integer/problem
//============================================================================
/* Description : 
You will be given an array of integers. All of the integers except one occur twice.
That one is unique in the array.
Given an array of integers, find and print the unique element.
For example, a = [1, 2, 3, 4, 3, 2, 1], the unique element is 4.

Function Description
Complete the lonelyinteger function to return the integer which occurs only once in
the input array.
lonelyinteger has the following parameter(s):
- a: an array of integers

Input Format
The first line contains a single integer, n, denoting the number of integers in the array.
The second line contains n space-separated integers describing the values in a.

Constraints : 
1 <= n < 100; 0 <= a[i] <= 100, 0 <= i < n
It is guaranteed that n is an odd number and that there is one unique element.

Output Format : Print the unique integer in the array.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lonelyinteger function below.
int lonelyinteger(vector<int> a) {
  int result = 0;
  // Succesive xor's will cancel each other out
  // i.e 6 ^ 6 ^ 8 ^ 8 ^ 9 = 9
  // IMPORTANT TO REMEBER: The order in which the xor's are applied doesn't matter (xor operators are "commutative" )
  // Also note: 0 ^ x  = x

  for(size_t i = 0; i < a.size(); i++) {
      result ^= a[i];
  }
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);

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
Sample Input 0
1
1
Sample Output 0
1
Explanation 0
There is only one element in the array, thus it is unique.

Sample Input 1
3
1 1 2
Sample Output 1
2
Explanation 1
We have two 1's, and 2 is unique.

Sample Input 2
5
0 0 1 2 1
Sample Output 2
2
Explanation 2
We have two 0's, two 1's, and one 2. 2 is unique.
*/
