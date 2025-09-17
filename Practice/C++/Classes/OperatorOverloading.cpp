//============================================================================
// Name        : OperatorOverloading.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/operator-overloading/problem
//============================================================================
/* Description :
You are given a main() function which takes a set of inputs to create two matrices and prints the result of their addition.
You need to write the class Matrix which has a member a of type vector<vector<int>>.
You also need to write a member function to overload the operator +.
The function's job will be to add two objects of Matrix type and return the resultant Matrix.

Input Format :
First line will contain the number of test cases T. For each test case, there are three lines of input.
The first line of each test case will contain two integers N and M which denote the number of the rows and columns respectively
of the two matrices that will follow on the next two lines.
These next two lines will each contain N * M elements describing the two matrices in row-wise format
i.e. first M elements belong to the first row, next M elements belong to the second row and so on.

Output Format :
The code provided in the editor will use your class Matrix and overloaded operator
function to add the two matrices and give the output.

Constraints : 1 <= T <= 1000; 1 <= N,M <= 100; 1 <= A[i,j] <= 10
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
public:
    vector<vector<int>> a;

    Matrix operator+(const Matrix& other)
    {
        Matrix result;
        int n = a.size();
        int m = a[0].size();

        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < m; j++)
            {
                row.push_back(a[i][j] + other.a[i][j]);
            }
            result.a.push_back(row);
        }

        return result;
    }
};

int main ()
{
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++)
   {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++)
      {
        vector<int> b;
        int num;
        for(j=0;j<m;j++) 
        {
            cin >> num;
            b.push_back(num);
        }
        x.a.push_back(b);
      }
      for(i=0;i<n;i++)
      {
        vector<int> b;
        int num;
        for(j=0;j<m;j++)
        {
            cin >> num;
            b.push_back(num);
        }
        y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}
