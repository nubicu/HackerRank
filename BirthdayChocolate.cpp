//Birthday Chocolate
/*
Lily has a chocolate bar that she wants to share it with Ron for his birthday. Each of the squares has an integer on it. 
She decides to share a contiguous segment of the bar selected such that the length of the segment mathches Ron's birth month and the sum of the 
integers on the squares is equal to his birth day. You must determine how many ways she can divide the chocolate.

Consider the chocolate bar as an array of squares, s=[2,2,1,3,2]. She wants to find segments summing to Ron's birth day, d=4 with a length equalling 
his birth month, m=2. In this case, there are two segments meeting her criteria: [2,2] and [1,3].

Input Format : First line - integer n(number of squares in the chocolate bar). 
The second line contains n space-separated integers s_i, the numbers on the chocolate squares where 0<=i<n. 
The third line contains two space-separated integers, d and m, Ron's birth day and his birth month.

Constraints : 1<=n<=100; 1<=s_i<=5; 1<=d<=31; 1<=m<=12 

Output Format: Print an integer denoting the total number of ways that Lily can portion her chocolate bar to share with Ron.
*/


#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector < int > s, int d, int m){
    int ways = 0;
    for(auto it = s.cbegin(); it != s.cend(); ++it){
        if(d == std::accumulate(it, it + m, 0))
            ways++;
    }
    return ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}



/*
Sample Input 0
5
1 2 1 3 2
3 2
Sample Output 0
2
Sample Input 1
6
1 1 1 1 1 1
3 2
Sample Output 1
0
Sample Input 2
1
4
4 1
Sample Output 2
1
*/

/* Explanation */
