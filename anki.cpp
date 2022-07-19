#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;



bool solution(string s, string t)
{
    stack<char> sstack;
    stack<char> tstack;

    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        if (!sstack.empty() && curr == '#')
        {
            sstack.pop();
            continue;
        }
        else 
        {
            sstack.push(curr);
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        char curr = t[i];
        if (!tstack.empty() && curr == '#')
        {
            tstack.pop();
            continue;
        }
        else 
        {
            tstack.push(curr);
        }
    }

    string new_s = "";
    string new_t = "";

    if (sstack.size() != tstack.size())
        return false;

    for (int i = 0; i < sstack.size(); i++)
    {
        char curr = sstack.top();
        new_s += curr;
    }

    for (int i = 0; i < tstack.size(); i++)
    {
        char curr = tstack.top();
        new_t += curr;
    }

    if (new_s == new_t)
        return true;
    else
        return false;

}



int main()
{
    return 0;
}