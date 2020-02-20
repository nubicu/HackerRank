//============================================================================
// Name        : CatsAndAMouse.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
//============================================================================
/* Description :
Two cats and a mouse are at various positions on a line. You will be given their starting positions.
Your task is to determine which cat will reach the mouse first, assuming the mouse doesn't move and
the cats travel at equal speed. If the cats arrive at the same time, the mouse will be allowed to
move and it will escape while they fight.
You are given q queries in the form of x, y, and z representing the respective positions for cats A
and B, and for mouse C. Complete the function catAndMouse to return the appropriate answer to each
query, which will be printed on a new line.
If cat A catches the mouse first, print Cat A.
If cat B catches the mouse first, print Cat B.
If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.
For example, cat A is at position x=2 and cat B is at y=5. If mouse  is at position z=4, it is 2
units from cat A and 1 unit from cat B. Cat B will catch the mouse.

Function Description
Complete the catAndMouse function to return one of the three strings as described.
catAndMouse has the following parameter(s):
x: an integer, Cat A's position
y: an integer, Cat B's position
z: an integer, Mouse C's position

Input Format
The first line contains a single integer, q, denoting the number of queries.
Each of the q subsequent lines contains three space-separated integers describing the respective
values of x(cat A's location), y(cat B's location), and z(mouse C's location).

Constraint : 1 <= q <= 100; 1 <= x,y,z <= 100

Output Format

For each query, return Cat A if cat A catches the mouse first, Cat B if cat B catches the mouse
first, or Mouse C if the mouse escapes.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
  string result ="";

  if( abs(x-z) < abs(y-z) )
    result = "Cat A";
  else if( abs(x-z) > abs(y-z) )
    result = "Cat B";
  else
    result = "Mouse C";

  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xyz_temp;
        getline(cin, xyz_temp);

        vector<string> xyz = split_string(xyz_temp);

        int x = stoi(xyz[0]);

        int y = stoi(xyz[1]);

        int z = stoi(xyz[2]);

        string result = catAndMouse(x, y, z);

        cout << result << "\n";
    }

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
2
1 2 3
1 3 2
Sample Output 0
Cat B
Mouse C
Explanation 0
Query 0: The positions of the cats and mouse are shown in the image.
Cat B will catch the mouse first, so we print Cat B on a new line.
Query 1: In this query, cats A and B reach mouse C at the exact same time.
Because the mouse escapes, we print Mouse C on a new line.
*/
