// Beautiful Days At The Movies
/*
Lily likes to play games with integers. She has created a new game where she determines the
difference between a number and its reverse. For instance, given the number 12, its reverse is 21.
Their difference is 9. The number 120 reversed is 21, and their difference is 99.
She decides to apply her game to decision making. She will look at a numbered range of days and will
only go to a movie on a beautiful day.
Given a range of numbered days, [i..j] and a number k, determine the number of days in the range
that are beautiful. Beautiful numbers are defined as numbers where |i-reverse(i)| is evenly
divisible by k. If a day's value is a beautiful number, it is a beautiful day. Print the number of
beautiful days in the range.

Function Description
Complete the beautifulDays function in the editor below. It must return the number of beautiful days in the range.
beautifulDays has the following parameter(s):
i: the starting day number
j: the ending day number
k: the divisor

Input Format
A single line of three space-separated integers describing the respective values of i, j, and k.

Constraints: 1<=i<=j<=2*10^6; 1<=k<=2*10^9

Output Format: Print the number of beautiful days in the inclusive range between i and j.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

static int do_reverse(const int& x) {
    std::string s = std::to_string(x);
    for (size_t i = 0; i < s.length()/2; ++i)
        std::swap(s[i], s[s.length()-i-1]);

    return std::stoi(s);
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
  int count = 0;

  for (int x = i ; x <= j; ++x)
        if (std::abs(x-do_reverse(x)) % k == 0)
         count++;

  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    cout << result << "\n";

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
20 23 6
Sample Output
2
Explanation
Lily may go to the movies on days 20, 21, 22, and 23. We perform the following calculations to
determine which days are beautiful:
Day 20 is beautiful because the following evaluates to a whole number: (|20-02|)/6=18/6=3
Day  is not beautiful because the following doesn't evaluate to a whole number: |21-12|/6=9/6=1.5
Day  is beautiful because the following evaluates to a whole number: |22-22|/6=0/6=0
Day  is not beautiful because the following doesn't evaluate to a whole number: |23-32|/6=9/6=1.5
Only two days, 20 and 22, in this interval are beautiful. Thus, we print 2 as our answer.
*/
