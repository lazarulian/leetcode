#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>

using namespace std;




class Solution
{
    public:
    string convert_ascii(string input);

};

int main()
{
    Solution s;

    string p = s.convert_ascii("HackerRank");

    cout << p << endl;

};


string Solution::convert_ascii(string input)
{
    const int s = input.size();
    string res = "";

    for (int i = 0; i < s; i++)
    {
        int ch = int(input[i]);
        res += std::to_string(ch);
    }

    reverse(res.begin(), res.end());

    return res;
};