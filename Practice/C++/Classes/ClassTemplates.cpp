//============================================================================
// Name        : ClassTemplates.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/c-class-templates/problem
//============================================================================
/* Description :
You are given a main() function which takes a set of inputs.
The type of input governs the kind of operation to be performed, i.e. concatenation for strings and addition for int or float.
You need to write the class template AddElements which has a function add() for giving the sum of int or float elements.
You also need to write a template specialization for the type string with a function concatenate() to concatenate
the second string to the first string.

Input Format : The first line contains an integer n.
Input will consist of n+1 lines where n is the number given in the first line of the input followed by n lines.
Each of the next n line contains the type of the elements provided and depending on the type,
either two strings or two integers or two floating point numbers will be given. The type will be one of int,
float or string types only. Out of the following two elements, you have to concatenate or add the second element to the first element.

Constraints : 1 <= n <= 5 * 10^5;
1.0 <= value_float <= 10.0
1 <= value_int <= 10^5
0 <= len_string <= 10

The time limit for this challenge is 4 seconds.

Output Format :
The code provided in the code editor will use your class template to add/append elements and give the output.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
class AddElements {
private:
    T element;
public:
    AddElements(const T& element) : element(element) {}

    T add(const T& other) {
        return element + other;
    }

    T concatenate(const T& other) {
        return element + other;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
