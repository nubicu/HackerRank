//Grading Students
/*
HackerLand University has the following grading policy:
- Every student receives a grade in the inclusive range from 0 to 100.
- Any grade less than 40 is a failing grade.
Sam is a professor at the university and likes to round each student's grade according to these rules:
- If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
- If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.

For example, grade=84 will be rounded to 85 but grade=29 will not be rounded because the rounding would result in a number that is less than 40.

Given the initial value of grade for each of Sam's n students, write code to automate the rounding process. 
Complete the function solve that takes an integer array of all grades, and return an integer array consisting of the rounded grades. 
For each grade_i, round it according to the rules above and print the result on a new line.

Input Format : First line - n(number of students) Next n lines individual integer grades

Constraints : 1<=n<=60; 0<=grade_i<=100

Output Format: Print n lines, each with the rounded value of a student’s grade in input order.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> returnVector;
    int next_multiple5=0;
    for(int i=0;i<grades.size();i++)
    {
        next_multiple5 = (grades[i]/5+1)*5;
        if(grades[i]<38) {returnVector.push_back(grades[i]);}
        else if (grades[i]%5 == 0) {returnVector.push_back(grades[i]);}
            else if ((next_multiple5 - grades[i]) < 3) { returnVector.push_back(next_multiple5); }
                else {returnVector.push_back(grades[i]);}
    }
    
    return returnVector;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> grades(n);

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

/*
Sample Input 0
4
73
67
38
33
Sample Output 0
75
67
40
33
*/

/* Explanation
Student 1 received a 73, and the next multiple of 5 from 73 is 75. Since 75-73<3, the student's grade is rounded to 75.
Student 2 received a 67, and the next multiple of 5 from 67 is 70. Since 70-67=3, the grade will not be modified and the student's final grade is 67.
Student 3 received a 38, and the next multiple of 5 from 38 is 40. Since 40-38<3, the student's grade will be rounded to 40.
Student 4 received a grade below 38, so the grade will not be modified and the student's final grade is 33.
*/
