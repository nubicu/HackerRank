// Angry Professor
/* 
A Discrete Mathematics professor has a class of students. Frustrated with their lack of discipline, he decides to cancel class if fewer than some number of students are present when class starts. Arrival times go from on time (arrivalTime <= 0) to arrived late (arrivalTime > 0).
Given the arrival time of each student, determine if the class is canceled.

Input Format : First line t = number of test cases. Each test case consists of two lines. 
The first line has two space-separated integers, n(students in the class) and k(the cancelation threshold).
The second line contains n space-separated integers (a1,a2,....,an) describing the arrival times for each student.

Note : Non-positive arrival times (ai<=0) indicate the student arrived early or on time; positive arrival times (ai > 0) indicate the student arrived ai minutes late

Constraints : 1<=t<=10; 1<=n<=1000; 1<=k<=n; -100<=ai<=100, where i in [1,n]

Output Format : For each test case, print the word YES if the class is canceled or NO if it is not.
Note : If a student arrives exactly on time (ai=0), the student is considered to have entered before the class started.
*/

#include <bits/stdc++.h>
using namespace std;

int c = 0;

string angryProfessor(int k, vector <int> a) {
    int c = 0;
    string returnString = "";
    
    for (int i=0; i<a.size();i++)
    {
        if(a[i]<=0) {c++;}
    }
    if(c>=k) { returnString = "NO"; }
    else { returnString = "YES"; }
    
    return returnString;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = angryProfessor(k, a);
        cout << result << endl;
    }
    return 0;
}

/*
Sample Input :
2
4 3
-1 -3 4 2
4 2
0 -1 2 1
Sample Output :
YES
NO
*/

/* Explanation :
For the first test case, k=3. The professor wants at least 3 students in attendance, but only 2 have arrived on time (-3 and -1) so the class is canceled.

For the second test case, k=2. The professor wants at least 2 students in attendance, and there are 2 who have arrived on time (0 and -1) so the class is not canceled.
*/
