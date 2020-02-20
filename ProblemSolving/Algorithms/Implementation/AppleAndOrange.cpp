//============================================================================
// Name        : AppleAndOrange.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/apple-and-orange/problem
//============================================================================
/* Description :
Sam's house has an apple tree and an orange tree that yield an abundance of fruit. In the diagram below, the red region denotes his house, 
where s is the start point, and t is the endpoint. The apple tree is to the left of his house, and the orange tree is to its right. 
You can assume the trees are located on a single point, where the apple tree is at point a, and the orange tree is at point b.

When a fruit falls from its tree, it lands d units of distance from its tree of origin along the x-axis. 
A negative value of d means the fruit fell d units to the tree's left, and a positive value of d means it falls d units to the tree's right.

Complete the function countApplesAndOranges where:
s = Starting point of Sam's house location. 
t = Ending location of Sam's house location. 
a = Location of the Apple tree. 
b = Location of the Orange tree. 
m = Number of apples that fell from the tree. 
apples = Distance at which each apple falls from the tree. 
n = Number of oranges that fell from the tree. 
oranges = Distance at which each orange falls from the tree.

Given the value of d for m apples and n oranges, can you determine how many apples and oranges will fall on Sam's house 
(i.e., in the inclusive range [s,t])? 
Print the number of apples that fall on Sam's house as your first line of output, then print the number of oranges that fall on Sam's house as your 
second line of output.

Input Format : First line - s and t (left and right sides of Sam's house)
Second line - a and b (Larry’s and Rob’s positions in the trees)
Third line - m and n (number of apples and oranges thrown)
Fourth line - m space-separated integers(distances m_i that each apple falls from a)
Fifth line - n space-separated integers (distances n_i that each orange falls from b)

Constraints : 1<=a,b,m,n,s,t<=100000; -100000<=m_i,n_i<=100000; 

Output Format: 2 space-separated integers on a line: Larry’s score followed by Rob’s score.
*/


#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int apcnt = 0,orcnt = 0;
	for(int i = 0;i < apples.size();i++)
	{
        if(a+apples[i] >= s && a+apples[i] <= t) {apcnt++;}
    }
	for(int i = 0;i < oranges.size();i++)
	{
		if(b+oranges[i] >= s && b+oranges[i] <= t) {orcnt++;}
	}
	
	cout << apcnt << endl<< orcnt;
}

int main()
{
    string st_temp;
    getline(cin, st_temp);
    vector<string> st = split_string(st_temp);
    int s = stoi(st[0]);
    int t = stoi(st[1]);

    string ab_temp;
    getline(cin, ab_temp);
    vector<string> ab = split_string(ab_temp);
    int a = stoi(ab[0]);
    int b = stoi(ab[1]);

    string mn_temp;
    getline(cin, mn_temp);
    vector<string> mn = split_string(mn_temp);
    int m = stoi(mn[0]);
    int n = stoi(mn[1]);

    string apple_temp_temp;
    getline(cin, apple_temp_temp);
    vector<string> apple_temp = split_string(apple_temp_temp);
    vector<int> apple(m);
    for (int apple_itr = 0; apple_itr < m; apple_itr++) {
        int apple_item = stoi(apple_temp[apple_itr]);
        apple[apple_itr] = apple_item;
    }

    string orange_temp_temp;
    getline(cin, orange_temp_temp);
    vector<string> orange_temp = split_string(orange_temp_temp);
    vector<int> orange(n);
    for (int orange_itr = 0; orange_itr < n; orange_itr++) {
        int orange_item = stoi(orange_temp[orange_itr]);
        orange[orange_itr] = orange_item;
    }

    countApplesAndOranges(s, t, a, b, apple, orange);

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
7 11
5 15
3 2
-2 2 1
5 -6
Sample Output 0
1 1
*/

/* Explanation
The first apple falls at position 5-2=3. 
The second apple falls at position 5+2=7. 
The third apple falls at position 5+1=6. 
The first orange falls at position 15+5=20. 
The second orange falls at position 15-6=9. 
Only one fruit (the second apple) falls within the region between 7 and 11, so we print 1 as our first line of output. 
Only the second orange falls within the region between 7 and 11, so we print 1 as our second line of output.
*/
