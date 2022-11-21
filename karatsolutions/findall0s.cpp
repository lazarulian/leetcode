#include <vector>
#include <iostream>
#include <unordered_set>;

using namespace std;

class Solution
{
    vector<vector<bool>> visited;

    void floodFill(vector<vector<int>>& matrix, int x, int y)
    {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() 
        || matrix[x][y] == -1 || visited[x][y] == true)
        {
            return;
        }
        visited[x][y] = true;
        floodFill(matrix, x-1, y);
        floodFill(matrix, x+1, y);
        floodFill(matrix, x, y-1);
        floodFill(matrix, x, y+1);
    }

    bool findLegal(vector<vector<int>>& matrix, int i, int j)
    {
        if (matrix.size() == 0 || matrix[0].size() ==0) return false;
        floodFill(matrix, i, j);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (!visited[i][j] && matrix[i][j] == 0) return false;
            }
        }
        return true;
    }
};



int main()
{
    return 0;
}