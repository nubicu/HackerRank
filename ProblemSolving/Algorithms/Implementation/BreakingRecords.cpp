//============================================================================
// Name        : BreakingRecords.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Description : 
/* Maria plays college basketball and wants to go pro.
  Each season she maintains a record of her play. She tabulates the number of times
  she breaks her season record for most points and least points in a game.
  Points scored in the first game establish her record for the season, and she begins
  counting from there.
  For example, assume her scores for the season are represented in the array
  Scores are in the same order as the games played. She would tabulate her results as
  follows:
                                   Count
Game  Score  Minimum  Maximum   Min Max
  0      12     12       12       0   0
  1      24     12       24       0   1
  2      10     10       24       1   1
  3      24     10       24       1   1
  Given Maria's scores for a season, find and print the number of times she breaks
  her records for most and least points scored during the season.

Function Description
  Complete the breakingRecords function in the editor below. It must return an integer
  array containing the numbers of times she broke her records. Index 0 is for breaking
  most points records, and index 1 is for breaking least points records.
  breakingRecords has the following parameter(s):
      scores: an array of integers

Input Format
  The first line contains an integer n, the number of games.
  The second line contains n space-separated integers describing the respective
  values of score0, score1, ....., score n-1

Constraints : 1 <= n <= 1000; 0 <= scores[i] <= 10^8

Output Format
  Print two space-seperated integers describing the respective numbers of times her
  best (highest) score increased and her worst (lowest) score decreased.
*/
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) {
	vector<int> result(2);
	int min = scores[0];
	int max = scores[0];
	int count_min = 0;
	int count_max = 0;

	for (size_t i = 1 ; i < scores.size(); i++)
	{
		if(scores[i]<min)
		{
			min = scores[i];
			count_min++;
		}
		if(scores[i]>max)
		{
			max = scores[i];
			count_max++;
		}
	}

	result[0] = count_max;
	result[1] = count_min;

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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

/* Sample Input 0
  9
  10 5 20 20 4 5 2 25 1
*/