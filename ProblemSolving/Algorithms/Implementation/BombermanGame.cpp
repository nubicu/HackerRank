//============================================================================
// Name        : BombermanGame.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/drawing-book/problem
//============================================================================
/* Description :
Bomberman lives in a rectangular grid. Each cell in the grid either contains a
bomb or nothing at all. Each bomb can be planted in any cell of the grid but once
planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it's
destroyed — along with anything in its four neighboring cells. This means that if
a bomb detonates in cell i,j, any valid cells (i+-1,j) and (i,j+-1) are cleared.
If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without
detonating, so there's no chain reaction.
Bomberman is immune to bombs, so he can move freely throughout the grid. Here's what he does:
1. Initially, Bomberman arbitrarily plants bombs in some of the cells, the initial state.
2. After one second, Bomberman does nothing.
3. After one more second, Bomberman plants bombs in all cells without bombs, thus
filling the whole grid with bombs. No bombs detonate at this point.
4. After one more second, any bombs planted exactly three seconds ago will detonate.
Here, Bomberman stands back and observes.
5. Bomberman then repeats steps 3 and 4 indefinitely.
Note that during every second Bomberman plants bombs, the bombs are planted simultaneously
(i.e., at the exact same moment), and any bombs planted at the same time will detonate at
the same time.
Given the initial configuration of the grid with the locations of Bomberman's first batch
of planted bombs, determine the state of the grid after N seconds.

For example, if the initial grid looks like:
...
.O.
...
it looks the same after the first second. After the second second, Bomberman has placed all his charges:
OOO
OOO
OOO
At the third second, the bomb in the middle blows up, emptying all surrounding cells:
...
...
...

Function Description
Complete the bomberMan function to return an array of strings that represent the grid in its final state.
bomberMan has the following parameter(s):
- n: an integer, the number of seconds to simulate
- grid: an array of strings that represents the grid

Input Format
The first line contains three space-separated integers r, c, and n, The number of rows, columns
and seconds to simulate.
Each of the next r lines contains a row of the matrix as a single string of c characters.
The "." character denotes an empty cell, and the O character (ascii 79) denotes a bomb.

Constraints : 1 <= r,c <= 200; 1 <= n <= 10^9

Subtask
1 <= n <= 200 for 40% of the maximum score.

Output Format
Print the grid's final state. This means R lines where each line contains C characters, and each
character is either a . or an O (ascii 79). This grid must represent the state of the grid after
n seconds.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<string> bomberMan(int n, vector<string> grid) {
    vector<string> set1 = grid, set2, set3;

    for(auto i = 0; i < grid.size(); i++)
        for(auto j = 0; j < grid[0].size(); j++)
            set1[i][j] = 'O';
    set2 = set3 = set1;
    for(auto i = 0; i < grid.size(); i++)
        for(auto j = 0; j < grid[0].size(); j++)
            if(grid[i][j] == 'O')
            {
                if(i > 0)
                    set2[i - 1][j]='.';
                if(i < grid.size() - 1)
                    set2[i + 1][j] = '.';
                if(j > 0)
                    set2[i][j - 1] = '.';
                if(j < grid[0].size() - 1)
                    set2[i][j + 1] = '.';
                set2[i][j] = '.';
            }
    for(auto i = 0; i < grid.size(); i++)
        for(auto j = 0; j < grid[0].size(); j++)
            if(set2[i][j] == 'O')
            {
                if(i > 0)
                    set3[i - 1][j] = '.';
                if(i < set2.size() - 1)
                    set3[i + 1][j] = '.';
                if(j > 0)
                    set3[i][j - 1] = '.';
                if(j < set2[0].size() - 1)
                    set3[i][j + 1] = '.';
                set3[i][j] = '.';
            }
    /*
    cout << "Printing grid, set1, set2 : \n";
    for(auto i = 0; i < grid.size(); i++) cout << grid[i] << endl;
    cout << endl << endl;
    for(auto i = 0; i < grid.size(); i++) cout << set1[i] << endl;
    cout << endl << endl;
    for(auto i = 0; i < grid.size(); i++) cout << set2[i] << endl;
    */

    if(0 == n % 2) return set1;
    if(1 == n) return grid;
    if(3 == n % 4) return set2;
    return set3;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
            cout << "\n";
        }
    }

    cout << "\n";
    fout << "\n";

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
6 7 3
.......
...O...
....O..
.......
OO.....
OO.....
Sample Output
OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO
Explanation
The initial state of the grid is:
.......
...O...
....O..
.......
OO.....
OO.....
Bomberman spends the first second doing nothing, so this is the state after 1 second:
.......
...O...
....O..
.......
OO.....
OO.....
Bomberman plants bombs in all the empty cells during his second second, so this is the state after 2 seconds:
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
In his third second, Bomberman sits back and watches all the bombs he planted 3 seconds ago detonate. This is the final state after  seconds:
OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO
*/