//============================================================================
// Name        : StringStream.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
//============================================================================
/* Description :
stringstream is a stream class to operate on strings. It implements input/output operations on memory (string) based streams. stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here
Operator >> Extracts formatted data.
Operator << Inserts formatted data.
Method str() Gets the contents of underlying string device object.
Method str(string) Sets the contents of underlying string device object.
Its header file is sstream.
One common use of this class is to parse comma-separated integers from a string (e.g., "23,4,56").

Function Description :
parseInts has the following parameters: 
string str: a string of comma separated integers
Returns:
vector<int>: a vector of the parsed integers.

Input Format : There is one line of n integers separated by commas.

Output Format : Print each number on a separate line.

Constraints : The length of str is less than 8 * 10^5.
*/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    vector<int> integers;
    stringstream ss(str);
    char ch;
    int number;
    while (ss >> number)
    {
        integers.push_back(number);
        ss >> ch; // Read and discard the comma
    }
    return integers;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
