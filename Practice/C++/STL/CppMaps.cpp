//============================================================================
// Name        : CppMaps.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/cpp-maps/problem
//============================================================================
/* Description :
You will be given Q queries. Each query is of one of the following three types:
1 x : Add an element x to the set.
2 x : Delete an element x from the set. (If the number x is not present in the set, then do nothing).
3 x : If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format :
The first line of the input contains Q where Q is the number of queries.
The next Q lines contain 1 query each.
The first integer, type of each query is the type of the query. If query is of type 1, it consists of one string and an integer
X and Y where X is the name of the student and Y is the marks of the student.
If query is of type 2 or 3,it consists of a single string X where X is the name of the student.

Output Format :
For queries of type 3 print the marks of the given student.

Constraints : 1 <= Q <= 10^5; 1 <= type <= 3; 1 <= abs(x) <= 6; 1 <= Y <= 10^3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q; 

    map<string, int> mp;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            string name;
            int marks;
            cin >> name >> marks;
            mp[name] += marks;
        } else if (type == 2) {
            string name;
            cin >> name;
            mp.erase(name);
        } else if (type == 3) {
            string name;
            cin >> name;

            cout << mp[name] << endl;
        }
    } 
    return 0;
}
