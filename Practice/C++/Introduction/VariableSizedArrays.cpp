//============================================================================
// Name        : VariableSizedArrays.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/variable-sized-arrays/problem
//============================================================================
/* Description :
Consider an n-element array, a, where each index i in the array contains a reference to an array of Ki integers 
(where the value of Ki varies from array to array). See the Explanation section below for a diagram.

Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and j denotes
an index in the array located at a[i]. For each query, find and print the value of element j in the array at location
a[i] on a new line.

Input Format : The first line contains two space-separated integers denoting the respective values of n (the number of 
variable-length arrays) and q (the number of queries).
Each line i of the n subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 
describing the k-element array located at a[i].
Each of the q subsequent lines contains two space-separated integers describing the respective values of i (an index in array a)
and j(an index in the array referenced by a[i]) for a query.

Constraints :
1 <= n <= 10^5
1 <= q <= 10^5
1 <= k <= 3*10^5
n <= sum(k) <= 3*10^5
0 <= i < n
0 <= j < k

All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than 10^6

Output Format : For each pair of i and j values(for each query), print a single integer that denotes the element located
at index  of the array referenced by a[i]. There should be a total of q lines of output.


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;

        arr[i].resize(size);

        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    for (int k = 0; k < q; k++) {
        int i, j;
        cin >> i >> j;

        cout << arr[i][j] << endl;
    }
    return 0;
}
