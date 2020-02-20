//============================================================================
// Name        : FunnyString.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/funny-string/problem
//============================================================================
/* Description :
In this challenge, you will determine whether a string is funny or not. To determine whether a string is funny, create a copy of the string in reverse e.g. abc -> cba. Iterating through each string, compare the absolute difference in the ascii values of the characters at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is the same for both strings, they are funny.

Note: The absolute value of x, is written as |x|.

Input Format : First line - integer t(number of test cases). 
The next t lines contain a string s.

Constraints : 1<=t<=10; 2<=length of s<=10000

Output Format : For each string s print whether it is Funny or Not Funny on a new line.
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string funnyString(string s){
    string resultString = "";
    int i=0,j=s.size(),d=1;
    
    for(i=0;i<j-1;i++)
    {
        if(!(abs(s[i+1]-s[i])==abs(s[j-i-1]-s[j-i-2])))
        {
            d=0;
            break;
        }
    }

    if(d==0)
    {
        resultString = "Not Funny";
    }
    else
    {
        resultString = "Funny";
    }

    return resultString;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}

/*
Sample Input :
2
acxz
bcxz
Sample Output :
Funny
Not Funny
*/

/* Explanation :
You can use r to store the reverse of s.

Test Case 0:  s="acxz" r="zxca"
  s            r
|c-a| = 2  = |x-z|
|x-c| = 21 = |c-x|
|z-x| = 2  = |a-c|
Each comparison is equal so we print Funny.

Test Case 1:  s="bcxz" r="zxcb"
  s            r
|c-b| = 1 != |x-z| = 2
At this point, we stop evaluating s and print Not Funny.
*/
