#include <vector>
#include <iostream>
#include <unordered_set>;

using namespace std;


class Solution
{
    vector<pair<int,int>> paths;
    int start;
    int end;

    void dfs(vector<vector<int>>& matrix, int x, int y, int remainTreasure)
    {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() 
        || matrix[x][y] == -1 || matrix[x][y] == 2)
        {
            return;
        }
        paths.push_back({x, y});
        int temp = matrix[x][y];
        if (temp == 1)
            remainTreasure--;
        if (x == end && y == end && remainTreasure == 0)
        {
            paths.push()
            path.pop();
        }

        visited[x][y] = true;
        dfs(matrix, x-1, y, remainTreasure);
        dfs(matrix, x+1, y, remainTreasure);
        dfs(matrix, x, y-1, remainTreasure);
        dfs(matrix, x, y+1, remainTreasure);
    }

    bool findTreasures(vector<vector<int>>& matrix, int s, int e)
    {
        if (matrix.size() == 0) return {};
        start = s;
        end = e;


    }
};