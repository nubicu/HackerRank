// Cut the sticks
/* 
You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks, discarding the shortest pieces until there are none left. At each iteration you will determine the length of the shortest stick remaining, cut that length from each of the longer sticks and then discard all the pieces of that shortest length. When all the remaining sticks are the same length, they cannot be shortened so discard them.
Given the lengths of n sticks, print the number of sticks that are left before each iteration until there are none left.

Note: Before each iteration you must determine the current shortest stick.

Input Format : The first line contains a single integer n. 
The next line contains n space-separated integers: a0, a1,...an-1, where ai represents the length of the i-th stick in array arr.

Constraints : 1<=n<=1000; 1<=a[i]<=1000

Output Format : For each operation, print the number of sticks that are cut, on separate lines.
*/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cutTheSticks(vector <int> arr) {
    vector<int> resultVector;
    int shortest_stick = 0, zero_counter=0;
    int result_counter=arr.size();
    
    sort(arr.begin(),arr.end());
    
    for(int out_index=0;out_index<arr.size();out_index++)
    {
        int sticks_cut=result_counter-zero_counter;
        if(sticks_cut==0) {break;}
        
        for(int minimum_finder=0;minimum_finder<arr.size();minimum_finder++)
        {
            if(arr[minimum_finder]>0) {shortest_stick=arr[minimum_finder]; break;}
        }
        
        resultVector.push_back(sticks_cut);
        
        for(int subtract_index=0;subtract_index<arr.size();subtract_index++)
        {
            arr[subtract_index]-=shortest_stick;
            if(arr[subtract_index]==0) {zero_counter++;}
        }
    }
    
    return resultVector;
}

int main() {
    int n; // number of sticks
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = cutTheSticks(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}

/*
Sample Input 0:
6
5 4 4 2 2 8
Sample Output 0:
6
4
2
1
Sample Input 1:
8
1 2 3 4 3 3 2 1
Sample Output 1:
8
6
4
1
*/

/* Explanation :
Sample Case 0 :
sticks-length        length-of-cut   sticks-cut
5 4 4 2 2 8             2               6
3 2 2 _ _ 6             2               4
1 _ _ _ _ 4             1               2
_ _ _ _ _ 3             3               1
_ _ _ _ _ _           DONE            DONE

Sample Case 1 :
sticks-length         length-of-cut   sticks-cut
1 2 3 4 3 3 2 1         1               8
_ 1 2 3 2 2 1 _         1               6
_ _ 1 2 1 1 _ _         1               4
_ _ _ 1 _ _ _ _         1               1
_ _ _ _ _ _ _ _       DONE            DONE
*/
