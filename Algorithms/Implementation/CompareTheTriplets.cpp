// Compare the Triplets
/* 
Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet A = (a[0],a[1],a[2]), and the rating for Bob's challenge to be the triplet B = (b[0],b[1],b[2]).

Your task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then Alice is awarded  point.
If a[i] < b[i], then Bob is awarded  point.
If a[i] = b[i], then neither person receives a point.
Comparison points is the total points a person earned.

Given A and B, can you compare the two challenges and print their respective comparison points?

Input Format : The first line contains 3 space-separated integers, a[0], a[1], and a[2], describing the respective values in triplet A.
The second line contains 3 space-separated integers, b[0], b[1], and b[2], describing the respective values in triplet B.

Constraints : 1<=a[i]<=100; 1<=b[i]<=100

Output Format : Print two space-separated integers denoting the respective comparison points earned by Alice and Bob.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

vector<int> solve(int a0, int a1, int a2, int b0, int b1, int b2) {
    vector<int> resultVector;
    int alice = 0, bob = 0;
    if(a0>b0) { alice++; }
    else if(a0<b0) { bob++; }
    if(a1>b1) { alice++; }
    else if(a1<b1) { bob++; }
    if(a2>b2) { alice++; }
    else if(a2<b2) { bob++; }
    
    resultVector.push_back(alice);
    resultVector.push_back(bob);
    
    return resultVector;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a0A1A2_temp;
    getline(cin, a0A1A2_temp);

    vector<string> a0A1A2 = split_string(a0A1A2_temp);

    int a0 = stoi(a0A1A2[0]);
    int a1 = stoi(a0A1A2[1]);
    int a2 = stoi(a0A1A2[2]);

    string b0B1B2_temp;
    getline(cin, b0B1B2_temp);

    vector<string> b0B1B2 = split_string(b0B1B2_temp);

    int b0 = stoi(b0B1B2[0]);
    int b1 = stoi(b0B1B2[1]);
    int b2 = stoi(b0B1B2[2]);

    vector<int> result = solve(a0, a1, a2, b0, b1, b2);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
Sample Input :
5 6 7
3 6 10
Sample Output :
1 1
*/

/* Explanation :
In this example:
A = (a[0],a[1],a[2]) = (5,6,7)
B = (b[0],b[1],b[2]) = (3,6,10)
Now, let's compare each individual score:

a[0]>b[0], so Alice receives 1 point.
a[1]=b[1], so nobody receives a point.
a[2]<b[2], so Bob receives 1 point.
Alice's comparison score is 1, and Bob's comparison score is 1. Thus, we print 1 1 (Alice's comparison score followed by Bob's comparison score) on a single line.
*/
