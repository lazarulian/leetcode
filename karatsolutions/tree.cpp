#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


using namespace std;

//// The input is int[][] input, input[0] is the parent of input[1], such as {{1,4}, {1,5} {2,5}, {3,6}, {6, 7}} will form the above graph
// Find all of the nodes with one or 0 parents.


class Solution
{
  public:
  
  vector<int> findNodes(vector<pair<int,int>> edges)
  { // find with 0 or 1 parent
    unordered_map<int, unordered_set<int>> map;
    vector<int> res;
    
    for (auto i : edges) 
    {
      map[i.second].insert(i.first);
      map[i.first];
    }
    
    
    for (auto it : map)
    {
      if (it.second.size() == 0 || it.second.size() == 1)
        res.push_back(it.first);
    }
    return res;
  }
};

int main() {
  vector<pair<int, int>> input = {{1,4}, {1,5}, {2,5}, {3,6}, {6, 7}};
  Solution s;
  vector<int> sol = s.findNodes(input);
  
  for (auto i : sol)
  {
    cout << i << endl;
  }
}
