// Sorted Increasing Order
// Return an array of the squares of each number sorted in increasing order

// Input: nums = [-4,-1,0,3,10]

// Input: nums = [-7,-3,2,3,11]


// We want to achieve this in O(n) time

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;



vector<int> sortedSquares(vector<int>& nums) 
{
    vector<int> ordered_squares(nums.size());

    if (nums[0] >= 0)
    { // easy none are negative
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i]*nums[i];
        }
        return nums;
    }
    else
    { // all are greater so easy
        int counter = nums.size()-1;
        for (int i = 0, j = nums.size()-1; i <= j; )
        {
            if (nums[j]*nums[j] > nums[i]*nums[i])
            {
                ordered_squares[counter] = nums[j]*nums[j];
                counter--;
                continue; 
            }
            else
            {
                ordered_squares[counter] = nums[i]*nums[i];
                counter--;
            }
        }
        return ordered_squares;
    }      
}

