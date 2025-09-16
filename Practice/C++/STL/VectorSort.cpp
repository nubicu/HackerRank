//============================================================================
// Name        : VectorSort.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/vector-sort/problem
//============================================================================
/* Description :
You are given N integers.Sort the N integers and print the sorted order.
Store the N integers in a vector. Vectors are sequence containers representing arrays that can change in size.

Input Format : The first line of the input contains N where N is the number of integers. The next line contains N integers.

Output Format : Print the integers in the sorted order one by one in a single line followed by a space.

Constraints : 1 <= N <= 10^5; 1 <= Vi <= 10^9, where Vi is the i-th integer in the vector
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;   
    return 0;
}
