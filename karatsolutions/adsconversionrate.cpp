#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
    unordered_map<string, string> map1;

    void matchuser(vector<string> all_user_ips)
    {
        for (string i : all_user_ips)
        {
            int c = i.find(',');
            string user = i.substr(0, c);
            string ip = i.substr(c + 1, i.size() - c - 1);

            map1[ip] = user;
        }
    }

    void dataprocessed(vector<string> all_user_ips, vector<string> completed_purchase_user_ids, vector<string> ad_clicks)
    {
        matchuser(all_user_ips);
        unordered_set<string> purchased(completed_purchase_user_ids.begin(), completed_purchase_user_ids.end());

        // Item, Bought, Total Clicks
        unordered_map<string, pair<int, int>> purchases;

        for (string i : ad_clicks)
        {
            int c1 = i.find(',');
            string ip = i.substr(0, c1);
            string rest = i.substr(c1 + 1, i.size() - c1 - 1);
            int c2 = rest.find(',');
            string item = rest.substr(c2 + 1, rest.size() - c2 - 1);

            purchases[item].second++;
            if (purchased.find(map1[ip]) != purchased.end())
            {
                purchases[item].first++;
            }
        }

        for (auto i : purchases)
        {
            cout << i.second.first << " of " << i.second.second << "  " << i.first;
        }
    }
};

int main()
{
    vector<string> all_user_ips = {
        "2339985511,122.121.0.155",
        "234111110,122.121.0.1",
        "3123122444,92.130.6.145",
        "39471289472,2001:0db8:ac10:fe01:0000:0000:0000:0000",
        "8321125440,82.1.106.8",
        "99911063,92.130.6.144"};

    vector<string> ad_clicks = {
        "122.121.0.1,2016-11-03 11:41:19,Buy wool coats for your pets",
        "96.3.199.11,2016-10-15 20:18:31,2017 Pet Mittens",
        "122.121.0.250,2016-11-01 06:13:13,The Best Hollywood Coats",
        "82.1.106.8,2016-11-12 23:05:14,Buy wool coats for your pets",
        "92.130.6.144,2017-01-01 03:18:55,Buy wool coats for your pets",
        "92.130.6.145,2017-01-01 03:18:55,2017 Pet Mittens",
    };

    vector<string> completed_purchase_user_ids = {
        "3123122444",
        "234111110",
        "8321125440",
        "99911063"
    };

    Solution m;
    m.dataprocessed(all_user_ips, completed_purchase_user_ids, ad_clicks);

    return 0;
}