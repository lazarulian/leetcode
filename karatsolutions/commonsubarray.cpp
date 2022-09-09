#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> longestCommonContinuousHistory(vector<string> nums1, vector<string> nums2)
{ //dp o(n^2) size and space

    if (nums1.size() == 0 || nums2.size()==0) return {};
        
        int maxn = 0;
        vector<string> res;
        
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > maxn)
                    {
                        maxn = dp[i][j];
                        res.clear();
                        for (int j = i-maxn; j < i; j++)
                        {
                            res.push_back(nums1[j]);
                        }
                    }
                }
            }
        }
        
        return res;
}

int main()
{
    vector<string> h1 = {"3234.html", "xys.html", "7hsaa.html"}; // user1
    vector<string> h2 = {"3234.html", "sdhsfjdsh.html", "xys.html", "7hsaa.html"}; // user2

    vector<string> h3 = longestCommonContinuousHistory(h1, h2);
    for (auto t : h3) cout << t << endl;

}