//============================================================================
// Name        : AttributeParser.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/attribute-parser/problem
//============================================================================
/* Description :
This challenge works with a custom-designed markup language HRML.
In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. 
Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde('~') and 
the name of the attribute. The tags may also be nested.

The opening tags follow the format:
<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:
</tag-name>

The attributes are referenced as:
tag1~value  
tag1.tag2~name
Given the source code in HRML format consisting of N lines, answer Q queries. 
For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.

Input Format : The first line consists of two space separated integers, N and Q. N specifies the number of lines in the 
HRML source program. Q specifies the number of queries.
The following  lines consist of either an opening tag with zero or more attributes or a closing tag.
There is a space after the tag-name, attribute-name, '=' and value. There is no space after the last value. 
If there are no attributes there is no space after tag name.
Q queries follow. Each query consists of string that references an attribute in the source program. More formally, 
each query is of the form tagi1,tagi2,tagi3,... tagim~attr-name where m >= 1 and tagi1, tagi2, tagim are valid tags in the input.

Output Format : Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.

Constraints : 1 <= N <= 20; 1 <= Q <= 20
Each line in the source program contains, at most, 200 characters.
Every reference to the attributes in the Q queries contains at most  characters.
All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
A tag can may have no attributes.
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<string> hrml;
    vector<string> query;

    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        hrml.push_back(temp);
    }

    for (int i = 0; i < q; i++) {
        string temp;
        getline(cin, temp);
        query.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for (int i = 0; i < n; i++)
    {
        string temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0, 2) == "</")
        {
            tag.pop_back();
        } else
        {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;

            string temp1 = "";
            if (tag.size() > 0)
            {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            }
            else
            {
                temp1 = t1;
            }

            tag.push_back(temp1);
            m[*tag.rbegin() + "~" + p1] = v1;

            while (ss)
            {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        if (m.find(query[i]) == m.end())
        {
            cout << "Not Found!\n";
        } else {
            cout << m[query[i]] << endl;
        }
    }

    return 0;
}
