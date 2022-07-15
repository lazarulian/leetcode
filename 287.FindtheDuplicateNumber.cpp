#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

// Optimal Solution

class Solution
{
public:
    // int findDuplicate(vector<int>& nums)
    // {
    //     const int range_low = 1;
    //     const int range_high = nums.size()-1;
    //     for (int i = 0; i < nums.size(); i++)
    //     {

    //     }
    // }
};

// First Attempt : Hashmap o(n) time, not o(1) space WORKS

// int findDuplicate(vector<int> &nums)
// { // o(n) time, o(n) space
//     unordered_set<int> values;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         // Finds Value Already In Set
//         if (values.find(nums[i]) != values.end())
//         {
//             return nums[i];
//         }
//         values.insert(nums[i]);
//     }

//     return -1;
// }

// Second Attempt

// int findDuplicate(vector<int> &nums)
// {
//     const int range_low = 1;
//     const int range_high = nums.size() - 1;

    
//     for (int i = 0; i < nums.size(); i++)
//     {

//     }

// }

int findDuplicate3(vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0]; 
        cerr  << "Slow: " << slow << endl;
		int fast = nums[nums[0]]; 
        cerr << "fast: " << fast << endl;


		while (slow != fast)
		{
			slow = nums[slow]; 
            cerr  << "Slow: " << slow << endl;
			fast = nums[nums[fast]]; 
            cerr << "fast: " << fast << endl;
		}

        cerr << "Slow became fast" << endl;

		fast = 0;
        cerr << fast << endl;

		while (fast != slow)
		{
			fast = nums[fast];
            cerr << "fast: " << fast << endl;
			slow = nums[slow];
            cerr << "Slow" << slow << endl;
		}
		return slow;
	}
	return -1;
}

int main()
{

    int m[5] = {3,1,3,4,2};
    vector<int> p;
    for (auto i = 0; i < 5; i++)
    {
        p.push_back(m[i]);
    }


    findDuplicate3(p);


}