// Bon Appetit
/*
Anna and Brian are sharing a meal at a restuarant and they agree to split the bill equally. Brian
wants to order something that Anna is allergic to though, and they agree that Anna won't pay for
that item. Brian gets the check and calculates Anna's portion. You must determine if his calculation
is correct.
For example, assume the bill has the following prices: bill=[2,4,6]. Anna declines to eat item
k=bill[2] which costs 6. If Brian calculates the bill correctly, Anna will pay (2+4)/2=3. If he
includes the cost of bill[2], he will calculate (2+4+6)/2=6. In the second case, he should refund 3
to Anna.

Function Description
Complete the bonAppetit function in the editor below. It should print Bon Appetit if the bill is
fairly split. Otherwise, it should print the integer amount of money that Brian owes Anna.
bonAppetit has the following parameter(s):
bill: an array of integers representing the cost of each item ordered
k: an integer representing the zero-based index of the item Anna doesn't eat
b: the amount of money that Anna contributed to the bill

Input Format
The first line contains two space-separated integers n and k, the number of items ordered and the
0-based index of the item that Anna did not eat.
The second line contains n space-separated integers bill[i] where 0<=i<n.
The third line contains an integer, b, the amount of money that Brian charged Anna for her share of
the bill.

Constraints
2<=n<=10^5; 0<=k<n; 0<=bill[i]<=10^4; 0<=b<=sum(bil[i]),0<=i<n
The amount of money due Anna will always be an integer

Output Format
If Brian did not overcharge Anna, print Bon Appetit on a new line; otherwise, print the difference
(i.e., b_charged-b_actual) that Brian must refund to Anna. This will always be an integer.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
  long int sum_of_elems = 0;
  int b_actual = 0;
  for(std::vector<int>::iterator it = bill.begin(); it != bill.end(); ++it) {
    sum_of_elems += *it;
  }
  b_actual = (sum_of_elems - bill[k]) / 2;
  if( b_actual == b) {
    cout << "Bon Appetit" << "\n";
  }
  else {
    if( b_actual > b) {
      cout << b_actual - b << "\n";
    }
    else {
      cout << b - b_actual << "\n";
    }
  }
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split(rtrim(nk_temp));

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string bill_temp_temp;
    getline(cin, bill_temp_temp);

    vector<string> bill_temp = split(rtrim(bill_temp_temp));

    vector<int> bill(n);

    for (int i = 0; i < n; i++) {
        int bill_item = stoi(bill_temp[i]);

        bill[i] = bill_item;
    }

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    bonAppetit(bill, k, b);

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/*
Sample Input 0
4 1
3 10 2 9
12
Sample Output 0
5
Explanation 0
Anna didn't eat item bill[1]=10, but she shared the rest of the items with Brian. The total cost of
the shared items is 3+2+9=14 and, split in half, the cost per person is b_actual=7. Brian charged
her b_charged=12 for her portion of the bill. We print the amount Anna was overcharged,
b_charged-b_actual=12-7=5, on a new line.

Sample Input 1
4 1
3 10 2 9
7
Sample Output 1
Bon Appetit
Explanation 1
Anna didn't eat item bill[1]=10, but she shared the rest of the items with Brian. The total cost of
the shared items is 3+2+9=14 and, split in half, the cost per person is b_actual=7.
Because b_actual=b_charged=7, we print Bon Appetit on a new line.
*/
