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

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// This is the two pointers solution.

class Solution
{
public:
    int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices)
{
    // o(n) solution, contains one forloop that will go through the array once to see it
    int max_p = 0;
    int min_buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            if (max_p < prices[i] - min_buy)
                max_p = prices[i] - min_buy;
        }
        else
        {
            if (min_buy > prices[i])
                min_buy = prices[i];
        }
    }

    return max_p;
}

int main()
{
    return 0;
}