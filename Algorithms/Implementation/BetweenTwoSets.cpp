//Between Two Sets
/*
You will be given two arrays of integers. You will be asked to determine all integers that satisfy the following two conditions:
1.The elements of the first array are all factors of the integer being considered
2.The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.

Complete the getTotalX function which takes 2 integer arrays a and b as parameters and returns an integer denoting the number of integers between 
the two sets.

Input Format : First line : n(number of elements in array a) and m(number of elements in array b).
The second line contains n distinct space-separated integers describing a_i. 
The third line contains m distinct space-separated integers describing b_i.

Constraints : 1<=n,m<=10; 1<=a_i,b_i<=100; 

Output Format: an integer denoting the number of integers between the two sets.
*/


#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

int getTotalX(vector<int> a, vector<int> b) {
    int start = a.back(), end = b.back();
    int count = 0;
    
    for(int x = start; x <= end; x++){
        // Booleans to test whether X fulfills condition
        bool a_pass = true, b_pass = true;
        
        for(const auto &ai : a){
            if(x % ai != 0){
                // If it doesn't, set flag and break out of A loop
                a_pass = false;
                break;
            }
        }
        
        // If A didn't complete successfully, continue with next integer
        if(!a_pass) {continue;}
        
        for(const auto &bi : b){
            if(bi % x != 0){
                // Idem A loop
                b_pass = false;
                break;
            }
        }
        
        // If both test were OK, count that integer
        if(a_pass && b_pass) {count++;}
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);
    vector<string> nm = split_string(nm_temp);
    int n = stoi(nm[0]);
    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);
    vector<string> a_temp = split_string(a_temp_temp);
    vector<int> a(n);
    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);
        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);
    vector<string> b_temp = split_string(b_temp_temp);
    vector<int> b(m);
    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);
        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

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
Sample Input 0
2 3
2 4
16 32 96
Sample Output 0
3
*/

/* Explanation
2 and 4 divide evenly into 4, 8, 12 and 16. 
4, 8 and 16 divide evenly into 16, 32, 96.
4, 8 and 16 are the only three numbers for which each element of A is a factor and each is a factor of all elements of B.
*/
