//============================================================================
// Name        : DequeSTL.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/deque-stl/problem
//============================================================================
/* Description :
Given a set of arrays of size N and an integer K, you have to find the maximum integer
for each and every contiguous subarray of size K for each of the given arrays.

Input Format :
First line of input will contain the number of test cases T.
For each test case, you will be given the size of array N and the size of subarray to be used K.
This will be followed by the elements of the array Ai.

Output Format :
For each of the contiguous subarrays of size K of each array, you have to print the maximum integer.

Constraints : 1 <= N <= 10^4; 1 <= T <= 1000; 1 <= K <= N; 1 <= A[i] <= 10^4
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    std::deque<int>  dq(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for ( ; i < n; ++i)
    {
        cout << arr[dq.front()] << " ";

        while ( (!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();

        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
 
    cout << arr[dq.front()] << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0)
    {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
