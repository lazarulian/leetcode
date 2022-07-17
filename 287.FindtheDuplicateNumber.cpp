#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

// Optimal Solution

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;

        do 
        {
            slow = slow[slow];
            fast = fast[fast];
        }
        while (slow != fast);
        
    }
};




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