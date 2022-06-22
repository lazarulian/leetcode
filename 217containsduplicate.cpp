#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, string> f;

        for (int i = 0; i < nums.size(); i++)
        {
            if (f.find(nums[i]) != f.end())
                return true;
            else
            {
                f[nums[i]] = i;
                continue;
            }
        }
        return false;

    }
};




int main()
{
    return 0;
}
