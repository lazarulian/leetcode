#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    size_t i = 0;
    vector<vector<int>> results;

    // Beginning
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
    {
        results.push_back(intervals[i]);
        i++;
    }

    // Middle
    while (i < intervals.size() && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    results.push_back(newInterval);

    // End
    while (i < intervals.size())
    {
        results.push_back(intervals[i]);
        i++;
    }
    
    return results;
}