#include <iostream>
#include <stack>
#include <queue>
#include <string>


using namespace std;
// "()[]{}"

class Solution {
public:
bool isValid(string s) 
{

    stack<char> pstack;

    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        if (curr == ')' || curr == '}' || curr ==']')
        {
            if (pstack.empty() == true)
                    return false;
        }
        switch(curr)
        {
            case '(':
                pstack.push(curr);
                break;
            case '{':
                pstack.push(curr);
                break;
            case '[':
                pstack.push(curr);
                break;
            case ')':
                if (pstack.top() != '(')
                {
                    return false;
                }
                else
                    pstack.pop();
                break;
            case '}':
                if (pstack.top() != '{')
                {
                    return false;
                }
                else
                    pstack.pop();
                break;
            case ']':
                if (pstack.top() != '[')
                {
                    return false;
                }
                else
                    pstack.pop();
                break;
        }
    }
    if (pstack.empty() != true)
    {
        return false;
    }
    return true;
}
};

int main()
{
    Solution m;
    assert(m.isValid("(") == false);
    assert(m.isValid("()") == true);
    assert(m.isValid("()(") == false);
    assert(m.isValid("[]") == true);
    assert(m.isValid("([]{})") == true);
    cout << "Passed all test cases" << endl;
}