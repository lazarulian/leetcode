#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>

using namespace std;




class Solution
{
    public:
    string encode(string input);
    string decode(string input);

};

int main()
{
    Solution s;
    
    cout << "Input String: HackerRank" << endl;
    string encoded_string = s.encode("HackerRank");
    cout << "Encoded String: " << encoded_string << endl;
    string decoded_string = s.decode(encoded_string);
    cout << "Decoded String: " << decoded_string << endl;
};


string Solution::encode(string input)
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


string Solution::decode(string input)
{
    // Reverse Encoding & Setup
    std::reverse(input.begin(), input.end());
    const int s = input.size();
    string res = "";

    // Decode Loop
    for (int i = 0; i < s; i++)
    {
        // 3 Letter Case
        if (input[i] == '1')
        {
            string ascii_str = input.substr(i, 3);
            int ascii_int = stoi(ascii_str);
            res += char(ascii_int);
            i += 2;
            continue;
        }
        else
        {
            string ascii_str = input.substr(i, 2);
            int ascii_int = stoi(ascii_str);
            res += char(ascii_int);
            i += 1;
            continue;
        }
    }

    return res;
}