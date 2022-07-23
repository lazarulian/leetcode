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


void sortColors(vector<int> &nums)
{
    int l = 0, r = nums.size()-1, curr = 0;
    int temp;

    while (curr <= r)
    {
        if (nums[curr] == 2)
        {
            nums[curr] = temp;
            nums[curr] = r;
            r = temp;
            r--;
            curr--;
        }
        else if (nums[curr] == 0)
        {
            nums[curr] = temp;
            nums[curr] = l;
            l = temp;
            l++;
        }
        curr++;
    }
}



void sortColors(vector<int> &nums)
{ // o(n) time o(n) space
    unordered_map<int, int> m;

    m[0] = 0;
    m[1] = 0;
    m[2] = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] += 1;
    }
    nums.clear();
    for (int i = 0; i < 3; i++)
    {
        while (m[i] != 0)
        {
            nums.push_back(i);
            m[i]--;
        }
    }
}