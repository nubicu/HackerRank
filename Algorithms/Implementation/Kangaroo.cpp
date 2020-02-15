// Kangaroo
/* 
You are choreograhing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).
The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.

You have to figure out a way to get both kangaroos at the same location as part of the show.

Complete the function kangaroo which takes starting location and speed of both kangaroos as input, and return Yes or No appropriately. Can you determine if the kangaroos will ever land at the same location at the same time? The two kangaroos must land at the same location after making the same number of jumps.

Input Format : 4 space-separated integers (x1,v1,x2,v2): starting locations xroo and meters per jump vroo for kangaroos 1 and 2

Constraints : 0<=x1<=x2<=10000; 1<=v1,v2<=10000

Output Format : Print YES if they can land on the same location at the same time. Otherwise, print NO.
*/

#include <bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    string returnResult="";
    for(;;)
    {
        if( (x1>x2&&v1>v2) ||(x2>x1&&v2>v1)||(x1!=x2&&v1==v2)) { returnResult = "NO\n"; break; }
        if((x1+=v1)==(x2+=v2)) { returnResult = "YES\n"; break; }
    }
    return returnResult;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << endl;
    return 0;
}

/*
Sample Input 0 :
0 3 4 2
Sample Output 0 :
YES
Sample Input 1 :
0 2 5 3
Sample Output 1 :
NO
*/

/* Explanation :
Test Case 0: It is clear that the kangaroos meet at the same location(number 12 on the number line) after same number of jumps(4 jumps), and we print YES.
Test Case 1: The second kangaroo has a starting location that is ahead (further to the right) of the first kangaroo's starting location (i.e., x2>x1). Because the second kangaroo moves at a faster rate (meaning v2>v1) and is already ahead of the first kangaroo, the first kangaroo will never be able to catch up. Thus, we print NO.
*/
