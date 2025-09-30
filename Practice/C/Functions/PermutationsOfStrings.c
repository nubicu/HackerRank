//============================================================================
// Name        : PermutationsOfStrings.c
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/permutations-of-strings/problem
//============================================================================
/* Description: 
Given an array of strings sorted in lexicographical order, print all of its permutations
in strict lexicographical order. If two permutations look the same, only print one of them.
See the ‘note’ below for an example.
Note: There may be two or more of the same string as elements of s.
For example, s = [ab, ab, bc]. Only one instance of a permutation where all elements match
should be printed. In other words, if s[0] == s[1], then print either s[0] s[1] or s[1] s[0] but not both.

A three element array having three distinct elements has six permutations as shown above.
In this case, there are three matching pairs of permutations where s[0] = ab and s[1] = ab are switched.
We only print the three visibly unique permutations:
ab ab bc
ab bc ab
bc ab ab

Complete the function next_permutation which generates the permutations in the described order.

Input Format:
The first line of each test file contains a single integer n, the length of the string array s.
Each of the next n lines contains a string s[i].

Constraints:
2 <= n <= 9
1 <= |s[i]| <= 10
s[i] contains only lowercase English letters.

Output Format: Print each permutation as a list of space-separated strings on a single line.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int i, int j)
{
    char * tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void reverse(char **s, int start, int end)
{
    while(start < end)
    {
        swap(s, start++, end--);
    }
}

int next_permutation(int n, char **s)
{
    /**
    * Complete this method
    * Return 0 when there is no next permutation and 1 otherwise
    * Modify array s to its next permutation
    */
    for(int i = n - 2; i > -1; i--)
    {
        if(strcmp(s[i + 1] ,s[i]) > 0)
        {
            //get min max
            for(int j = n - 1; j > i; j--)
            {
                if(strcmp(s[j], s[i]) > 0)
                {
                    //do swap
                    swap(s, i, j);
                    // do reverse
                    reverse(s, i + 1, n - 1);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}
