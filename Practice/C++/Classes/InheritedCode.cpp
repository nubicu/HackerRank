//============================================================================
// Name        : InheritedCode.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/inherited-code/problem
//============================================================================
/* Description :
You inherited a piece of code that performs username validation for your company's website. 
The existing function works reasonably well, but it throws an exception when the username is too short. 
Upon review, you realize that nobody ever defined the exception.
The inherited code is provided for you in the locked section of your editor. Complete the code so that, 
when an exception is thrown, it prints Too short: n (where n is the length of the given username).

Input Format :
The first line contains an integer, t, the number of test cases.
Each of the t subsequent lines describes a test case as a single username string, u.

Constraints : 1 <= t <= 1000; 1 <= abs(u) <= 100 (The username consists only of uppercase and lowercase letters.)

Output Format :
You are not responsible for directly printing anything to stdout. 
If your code is correct, the locked stub code in your editor will print either Valid (if the username is valid), 
Invalid (if the username is invalid), or Too short: n (where  is the length of the too-short username) 
on a new line for each test case.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException {
    private: 
        int n;
    public:
        BadLengthException(int errornumber)
        {
            n = errornumber;
        }
    
        int what() {return n;}
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if(n < 5) {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T; cin >> T;
    while(T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}
