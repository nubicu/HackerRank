//============================================================================
// Name        : SherlockAndAnagrams.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
//============================================================================
/* Description :
Two strings are anagrams of each other if the letters of one string can be rearranged
to form the other string. Given a string, find the number of pairs of substrings of
the string that are anagrams of each other.
For example s = mom, the list of all anagrammatic pairs is [m, m], [mo, om] at positions
[[0],[2]], [[0, 1], [1,2]] respectively.

Function Description
Complete the function sherlockAndAnagrams to return an integer that represents the number
of anagrammatic pairs of substrings in s.
sherlockAndAnagrams has the following parameter(s):
- s: a string .

Input Format
The first line contains an integer q, the number of queries.
Each of the next q lines contains a string s to analyze.

Constraints : 1 <= q <= 10; 2 <= |s| <= 100
String s contains only lowercase letters which are part of ascii[a-z].

Output Format
For each query, return the number of unordered anagrammatic pairs.
*/

#include <bits/stdc++.h>

using namespace std;

int sherlockAndAnagrams(string s) {
    map<string, int> m;
    int result = 0;
    
    int len = (int)s.size();

    m.clear();
    for (int i = 0; i < len; i++)
    {
        for (int l = 1; i + l - 1 < len; l++)
        {
            string t = s.substr(i, l);
            sort(t.begin(), t.end());
            m[t]++;
        }
    }

    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
        result += (long long)(it->second) * (it->second - 1) / 2;

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

/*
Sample Input 0
2
abba
abcd
Sample Output 0
4
0
Explanation 0
The list of all anagrammatic pairs is [a,a], [ab,ba], [b,b] and [abb,bba] at positions
[[0],[3]], [[0,1],[2,3]], [[1],[2]] and [[0,1,2],[1,2,3]] respectively.
No anagrammatic pairs exist in the second query as no character repeats.

Sample Input 1
2
ifailuhkqq
kkkk
Sample Output 1
3
10
Explanation 1
For the first query, we have anagram pairs [i,i], [q,q] and [ifa,fai] at positions
[[0],[3]], [[8],[9]] and [[0,1,2], [1,2,3]] respectively.
For the second query:
There are 6 anagrams of the form [k,k] at positions [[0],[1],[[0],[3]], [[1],[2]], [[1],[3]]] and [[2],[3]].
There are 3 anagrams of the form [kk,kk] at positions [[0,1],[1,2]], [[0,1],[2,3]] and [[1,2],[2,3]].
There is 1 anagram of the form [kkk,kkk] at position [[0,1,2],[1,2,3]].

Sample Input 2
1
cdcd
Sample Output 2
5
Explanation 2
There are two anagrammatic pairs of length 1: [c,c] and [d,d].
There are three anagrammatic pairs of length 2: [cd,dc], [cd,cd], [dc,cd] at positions 
[[0,1],[1,2]], [[0,1],[2,2]], [[1,2],[2,3]] respectively.
*/