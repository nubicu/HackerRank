//Sherlock and the Beast
/*
Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with their supercomputer, The Beast.
Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast with a virus. He also gives him a clue: an integer. Sherlock determines the key to removing the virus is to find the largest Decent Number having that number of digits.

A Decent Number has the following properties:
Its digits can only be 3's and/or 5's.
The number of 3's it contains is divisible by 5.
The number of 5's it contains is divisible by 3.
It is the largest such number for its length.
Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. Your task is to help Sherlock find the key before The Beast is destroyed!

Complete the code stub below to determine and print the Decent Number for the given length or -1 if such a number doesn't exist.

Input Format : first line - integer (t) = the number of test cases. The next t lines each contain an integer n, the number of digits in the number.

Constraints : 1<=t<=20 and 1<=n<=100 000

Output Format : Print the largest Decent Number having  digits; if no such number exists, tell Sherlock by printing -1.
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Number of testcases : ";
    cin>>t;

    while(t--)
    {
        int n;
        cout << "Number of digits in the number : ";
        cin>>n;
        int x=-1,y=-1;

        for(int i=n/3;i>=0;i--)
            if((n-3*i)%5==0)
            {
                x=i;
                y=(n-3*i)/5;
                break;
            }
            cout << "The largest Decent Number having " << n << " digits; if no such number exists, tell Sherlock by printing -1. : ";
            if(x==-1)
                cout<<"-1"<<endl;
            else
            {
                for(int i=0;i<3*x;i++)
                    cout<<"5";
                for(int i=0;i<5*y;i++)
                    cout<<"3";
                cout<<endl;
            }
    }
    cout << "End of the program!" << endl;
    return 0;
}