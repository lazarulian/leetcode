#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s)
{ // o(3n) o(n)

    unordered_map<char, int> m;
    int total;

    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        m[curr]++;
    }

    for (auto it : m)
    {
        if (it.second % 2 == 0)
            total += it.second;
        else
            total += round(it.second/2)* 2;
    }

    return total;
}

int main()
{

    string m = "abccccdd";
    cout << longestPalindrome(m) << endl;
}