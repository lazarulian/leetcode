#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.

// You can return the answer in any order.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Solution
// I would want to use some sort of datastructure that will inform me whether the number has 
// been used already, okay in this case it would be a dictionary

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> p;
    unordered_map<int, int>::iterator it;
    for (int i = 0; i < nums.size(); i++)
    {
        if (p.find(target-nums[i]) != p.end())
        {
            vector<int> gh;
            gh.push_back(p.at(target-nums[i]));
            gh.push_back(i);
            return gh;
        }
        else
        {
            p.insert(nums[i], i);
            continue;
        }
    }
}




int main()
{
    vector<int> k{2, 7, 11, 15};
    int target = 9;

    vector<int> d = twoSum(k, 9);
    cout << d[0] << ", " << d[1] << endl;


}