#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution
{
public:
    vector<int> orderedtwoSum(vector<int> &nums, int target);
    vector<int> twoSum(vector<int> &nums, int target);

private:
};


vector<int> Solution::twoSum(vector<int> &nums, int target)
{ // uses a hashmap to calculate check whether the index exists already within the vector

    unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
}

// // this will work for ordered vectors
// vector<int> Solution::orderedtwoSum(vector<int> &nums, int target)
// {

//     int i = 0;
//     int j = nums.size() - 1;
//     vector<int> indexes;
//     sort(nums.begin(), nums.end());

//     for (; i < j;)
//     {
//         if (nums[i] + nums[j] != target)
//         {
//             if (nums[i] + nums[j] < 9)
//             {
//                 i++;
//             }
//             else
//             {
//                 j--;
//             }
//         }
//         else
//         {
//             indexes.push_back(i);
//             indexes.push_back(j);
//             break;
//         }
//     }
//     cout << "The indexes are: " << indexes[0] << ", " << indexes[1] << endl;
//     return indexes;
// }


int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(15);
    int target = 9;

    Solution m;

    m.twoSum(nums, target);
}
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]