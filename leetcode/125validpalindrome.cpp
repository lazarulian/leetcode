#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    { // o(n) or o(i-j)
        // Initial Easy Cases
        int j = s.size() - 1;

        for (int i = 0; i < j;)
        {
            // Cleanup Cases
            // Capitalization
            if (int(s[i]) > 64 && int(s[i]) < 91)
                s[i] = tolower(s[i]);
            if (int(s[j]) > 64 && int(s[j]) < 91)
                s[j] = tolower(s[j]);
            // out of range
            if (int(s[i]) < 97 && int(s[i]) > 57 || int(s[i]) < 48 || int(s[i]) > 122)
            {
                i++;
                continue;
            }
            if (int(s[j]) < 97 && int(s[j]) > 57 || int(s[j]) < 48 || int(s[j]) > 122)
            {
                j--;
                continue;
            }
            // Regular Test Cases
            if (s[i] == s[j])
            {
                j--;
                i++;
                cerr << "Passed" << endl;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    assert(s.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(s.isPalindrome("racecar") == true);
    assert(s.isPalindrome("a") == true);
    assert(s.isPalindrome("fart") == false);
    assert(s.isPalindrome("aa") == true);
    assert(s.isPalindrome("efcafe") == false);
    cout << "Passed all test cases" << endl;
}