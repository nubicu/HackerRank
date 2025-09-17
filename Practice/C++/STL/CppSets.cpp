//============================================================================
// Name        : CppSets.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/cpp-sets/problem
//============================================================================
/* Description :
You will be given Q queries. Each query is of one of the following three types:
1 x : Add an element x to the set.
2 x : Delete an element x from the set. (If the number x is not present in the set, then do nothing).
3 x : If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format :
The first line of the input contains Q where Q is the number of queries. 
The next Q lines contain 1 query each. Each query consists of two integers y and x where 
y is the type of the query and x is an integer.

Output Format :
For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if the number is not present,
then print "No"(without quotes).
Each query of type 3 should be printed in a new line.

Constraints : 1 <= Q <= 10^5; 1 <= Y <= 3; 1 <= X <= 10^9
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int Q;
    cin >> Q;

    set<int> s;

    for (int i = 0; i < Q; i++) {
        int queryType, queryValue;
        cin >> queryType >> queryValue;

        if (queryType == 1) {
            s.insert(queryValue);
        } else if (queryType == 2) {
            s.erase(queryValue);
        } else if (queryType == 3) {
            set<int>::iterator it = s.find(queryValue);
            if (it != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
