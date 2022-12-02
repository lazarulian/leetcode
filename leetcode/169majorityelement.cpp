class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // Initial Setup
        int votes = 1;
        int candidate = nums[0];
        
        // Algorithm
        for (int i = 1; i < nums.size(); i++)
        {
            candidate == nums[i] ? votes++ : votes--;
           if (votes == 0)
           {
               candidate = nums[i+1];
           }
        }
        return candidate;
    }
    
};