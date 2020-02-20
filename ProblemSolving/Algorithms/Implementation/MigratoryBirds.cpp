//============================================================================
// Name        : MigratoryBirds.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/migratory-birds/problem
//============================================================================
/* Description : 
You have been asked to help study the population of birds migrating across the continent. Each type of bird you are interested in will be 
identified by an integer value. Each time a particular kind of bird is spotted, its id number will be added to your array of sightings. You would 
like to be able to find out which type of bird is most common given a list of sightings.If two or more types of birds are equally common, choose the 
type with the smallest ID number.

Complete the migratoryBirds function which takes 2 arguments, an integer n and an integer array ar and returns an integer denoting the type number of 
the most common bird.

Input Format : The first line contains an integer denoting n, the number of birds sighted and reported in the array ar. 
The second line describes ar as n space-separated integers representing the type numbers of each bird sighted.

Constraints : 5<=n<=2*10^5; It is guaranteed that each type is 1, 2, 3, 4, or 5. 

Output Format: Print an integer denoting the type number of the most common bird.
*/


#include <bits/stdc++.h>
using namespace std;

int migratoryBirds(int n, vector<int> types) {
    int tmp = -1, index = -1,mxNum = -1;
    
     for(int i = 0; i < types.size(); i++) {
         if(types[i] > mxNum) {mxNum = types[i];}
    }
    vector<int> cnt(mxNum,0);
    for(int i = 0; i < types.size(); i++){
        cnt[types[i]]++;
    }
    for(int i = 0; i <= mxNum; i++){
        if(cnt[i] > tmp){
            tmp = cnt[i];
            index = i;
        }
    }
    
    return index;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}


/*
Sample Input 0
6
1 4 4 4 5 3
Sample Output 0
4
*/

/* Explanation 
The different types of birds occur in the following frequencies:

Type 1: 1 bird
Type 2: 0 birds
Type 3: 1 bird
Type 4: 3 birds
Type 5: 1 bird
The type number that occurs at the highest frequency is type 4, so we print 4 as our answer.
*/
