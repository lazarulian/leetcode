#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t) 
{
    string sstring;
    string jstring;

    stack<char> sstack, tstack;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#' && !sstack.empty())
        {
            sstack.pop();
            continue;
        }
        else
        {
            if (s[i] != '#')
                {sstack.push(s[i]);}
            continue;
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '#' && !tstack.empty())
        {
            tstack.pop();
            continue;
        }
        else
        {
            if (t[i] != '#')
                {tstack.push(t[i]);}
            continue;
        }
    }

    if(sstack.size() != tstack.size())
        return false;
    
    else
    {
        while (!sstack.empty())
        {
            sstring += sstack.top();
            sstack.pop();
            continue;
        }
        while (!tstack.empty())
        {
            jstring += tstack.top();
            tstack.pop();
            continue;
        }

        cout << sstring << endl << jstring << endl;
        return sstring == jstring;
    }
}

int main()
{


    string d = "xywrrmp";
    string p = "xywrrmu#p";

    backspaceCompare(d, p);




}