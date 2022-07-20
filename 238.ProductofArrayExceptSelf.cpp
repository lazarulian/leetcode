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

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> results(nums.size());

    // Prefix Array

    results[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        results[i] = results[i - 1] * nums[i - 1];
    }

    // Postfix Array
    int post_fix = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        results[i] = results[i] * post_fix;
        post_fix *= nums[i];
    }

    return results;
}

int main()
{
    vector<int> m(9);
    cout << m[2] << endl;
    return 0;
}