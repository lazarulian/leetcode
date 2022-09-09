#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cassert>

using namespace std;

// 2. Whether the two nodes have a common ancestor



class Solution
{
  public:
  unordered_map<int, unordered_set<int>> adj;
  unordered_set<int> p1;
  unordered_set<int> p2;
  
  void findParents(int x, unordered_set<int>& used)
  {
    // BFS to find all Parents
    queue<int> q;
    q.push(x);
    
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      if(adj[curr].size() == 0) continue;
      else
      {
        for (auto i : adj[curr])
        {
          if (used.find(i) != used.end()) continue;
          else
          {
            used.insert(i);
            q.push(i);
          }
        }
      }
    }
  }
  
  bool commonAncestor(vector<pair<int, int>> edges, int x, int y)
  {
    // Creating ADJ List
    for (auto i : edges)
    {
      adj[i.second].insert(i.first);
      adj[i.first];
    }
    
    // BFS
    p1.clear();
    p2.clear();
    findParents(x, p1);
    findParents(y, p2);
    
    for (auto i : p1) cout << i << endl;    
    for (auto i : p2) cout << i << endl;    
    
    for (auto i : p1)
    {
      if (p2.find(i) != p2.end()) return true;
    }
    
    return false;
  }
};


int main() 
{
  
  vector<pair<int, int>> input = {{1,4}, {1,5}, {2,5}, {3,6}, {6, 7}};
  Solution s;
  assert(s.commonAncestor(input, 4, 7) == false);
  assert(s.commonAncestor(input, 4, 5) == true);
  assert(s.commonAncestor(input, 1, 7) == false);
  
  
}
