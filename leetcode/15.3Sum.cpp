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


vector<vector<int>> threeSum(vector<int>& nums) {
 
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> res;
    
    for(int i=0; i<nums.size()-1; i++) {
        
        int l=i+1, r=nums.size()-1;
        
        if(i!=0  && nums[i]==nums[i-1]) continue;
        
        while(l<r) 
        {
            int target = nums[l] + nums[r] + nums[i];
            
            if(target < 0) 
            {
                l++;         
            }
            else if(target>0) 
                 r--;    // reduce the target
            else {
                res.push_back( {nums[i], nums[l], nums[r]} );
                while(r-1>=l && nums[r-1]==nums[r]) r--;
                while(l+1<r && nums[l+1]==nums[l] ) l++;

                l++;
                r--; 
            }

        }
    }
    
    return res;
}


vector<vector<int>> threeSum(vector<int>& nums) 
{ // o(nlogn)
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;
 
    for (int i = 0; i < nums.size(); i++)
    {
        int l = i+1, r = nums.size()-1;
        
        if (nums[i] == nums[i-1] && i != 0) 
            continue;
        
        while (l < r)
        {
            int target = nums[i] + nums[l] + nums[r];
            
            if (target > 0)
                {r--;}
            else if (target < 0)
                {l++;}
            else 
            {
                results.push_back({nums[i], nums[l], nums[r]});
                while (r-1 >= l && nums[r-1] == nums[r]) r--;
                while (l+1 < r && nums[l+1] == nums[l]) l++;
                
                r--;
                l++;
            }
        }
    }
    return results;
 
}






int main()
{
    return 0;
}