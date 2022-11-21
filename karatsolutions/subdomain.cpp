#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        vector<string> res;

        for (string word : cpdomains)
        {
          int i = word.find(" ");
          int num = stoi(word.substr(0, i));
          string s = word.substr(i+1, word.size()-i-1);

          for (int j = s.size()-1; j >= 0; j--)
          {
            if (j == 0) map[s.substr(j, s.size()-j)] += num;
            if (s[j] == '.') map[s.substr(j+1, s.size()-j-1)] += num;
          }
        }

        for (auto i : map)
        {
          res.push_back(to_string(i.second) + " " + i.first);
        }
        
        return res;
    }
};