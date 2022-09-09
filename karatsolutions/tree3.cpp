#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cassert>

using namespace std;

// 2. Farthest Ancestor

class Solution
{
public:
    unordered_map<int, unordered_set<int>> adj;

    int farthest(vector<pair<int, int>> edges, int x)
    {
        // Creating ADJ List
        for (auto i : edges)
        {
            adj[i.second].insert(i.first);
            adj[i.first];
        }

        unordered_set<int> used;
        int farthest;

        queue<int> q1;
        q1.push(x);

        while (!q1.empty())
        {
            queue<int> q2;
            int n = q1.size();

            while (n--)
            {
                int curr = q1.front();
                q1.pop();
                q2.push(curr);
                if (adj[curr].size() == 0)
                {
                    farthest = q2.front();
                    continue;
                }
                else
                {
                    for (auto i : adj[curr])
                    {
                        if (used.find(i) != used.end())
                        {
                            continue;
                        }
                        else
                        {
                            used.insert(i);
                            q1.push(i);
                        }
                    }
                }
            }
        }

        return farthest;
    }
};

int main()
{

    vector<pair<int, int>> input = {{1, 4}, {1, 5}, {2, 5}, {99, 2}, {3, 6}, {6, 7}};
    Solution s;

    cout << s.farthest(input, 5) << endl;
}
