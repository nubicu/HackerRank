// Chocolate Feast
/* 
Little Bobby loves chocolate. He frequently goes to his favorite store to buy them. If Bobby saves enough wrappers, he can turn them in for a free chocolate (promotion)
Complete the chocolateFeast function in the code stub below to return the number of chocolates Bobby can eat with a given amount of money after taking full advantage of the promotion.
Note: Little Bobby will always turn in his wrappers if he has enough to get a free chocolate.

Input Format : First line - integer(t) = number of scenarios to analyze. Each of the next t lines contains three space-separated integers: money to spend (n), cost of a chocolate(c), and the number of wrappers he can turn in for a free chocolate(m).

Constraints : 1<=t<=1000; 2<=n<=100000; 1<=c<=n; 2<=m<=name

Output Format : For each trip to the store, print the total number of chocolates Bobby eats on a new line.
*/

#include <bits/stdc++.h>
using namespace std;

int chocolateFeast(int n, int c, int m) {
    int w, choc;
    
    choc=n/c; // Number of chocolates that he can buy with the ammount of money he have
    if(choc>=m)
        for(w=choc;w>=m;choc++,w=w-m+1);
    
    return choc;
}

int main() {
    int t; // Number of scenarios to analyze 
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n, c, m;
        cin >> n >> c >> m; // money to spend (n), cost of a chocolate(c), and the number of wrappers he can turn in for a free chocolate(m). 
        int result = chocolateFeast(n, c, m);
        cout << result << endl; // Number of chocolates eaten by Bobby
    }
    return 0;
}
/*
Sample Input :
3
10 2 5
12 4 4
6 2 2
Sample Output :
6
3
5
*/

/* Explanation :
Bobby makes the following 3 trips to the store:

He spends his 10 dollars on 5 chocolates at 2 dollars apiece. He then eats them and exchanges all 5 wrappers to get 1 more. He eats 6 chocolates.
He spends his 12 dollars on 3 chocolates at 4 dollars apiece. He has 3 wrappers, but needs 4 to trade for his next chocolate. He eats 3 chocolates.
He spends 6 dollars on 3 chocolates at 2 dollars apiece. He then exchanges 2 of the 3 wrappers for 1 additional piece. Next, he uses his third leftover chocolate wrapper from his initial purchase with the wrapper from his trade-in to do a second trade-in for 1 more piece. At this point he has 1 wrapper left, which is not enough to perform another trade-in. He eats 5 chocolates.
*/
