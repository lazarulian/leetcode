#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

// Optimal Solution

class Solution
{
public:
    int solution(vector<int> nums)
    {

        int fast = 0;
        int slow = 0;

        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        
        int slow2 = 0;
        do
        {
            slow2 = nums[slow2];
            slow = nums[slow];
        } while (slow2 != slow);

        return slow2;
    }
};

int main()
{

    int m[5] = {3, 1, 3, 4, 2};
    vector<int> p;
    for (auto i = 0; i < 5; i++)
    {
        p.push_back(m[i]);
    }

    findDuplicate3(p);
}