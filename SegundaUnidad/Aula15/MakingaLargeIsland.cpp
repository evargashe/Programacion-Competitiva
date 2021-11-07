/* https://leetcode.com/problems/making-a-large-island/
 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <cmath>
#include <iterator>
#include <deque>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <random>
#include <time.h>
using namespace std;



void dfs(vector<vector<int>>& grid, int i, int j, int idx, int& count)
{
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
    {
        return;
    }
    
    grid[i][j] = idx;
    ++count;
    dfs(grid, i + 1, j, idx, count);
    dfs(grid, i - 1, j, idx, count);
    dfs(grid, i, j + 1, idx, count);
    dfs(grid, i, j - 1, idx, count);
}

int largestIsland(vector<vector<int>>& grid) 
{
    int idx = 2, totalArea = 0, maxArea = 0;
    unordered_map<int, int> cnt;
    for(int i = 0; i != grid.size(); ++i)
    {
        for(int j = 0; j != grid[0].size(); ++j)
        {
            if(grid[i][j] == 1)
            {
                int count = 0;
                dfs(grid, i, j, idx, count);
                cnt[idx++] = count;
                totalArea += count;
                maxArea = max(maxArea, count + 1);
            }
        }
    }
    
    if(totalArea == 0)
    {
        return 1;
    }
    
    if(totalArea == grid.size() * grid[0].size())
    {
        return totalArea;
    }
    
    for(int i = 0; i != grid.size(); ++i)
    {
        for(int j = 0; j != grid[0].size(); ++j)
        {
            unordered_set<int> visited;
            int area = 1;
            if(i > 0 && grid[i - 1][j] != 0 && visited.find(grid[i - 1][j]) == visited.end())
            {
                visited.insert(grid[i - 1][j]);
                area += cnt[grid[i - 1][j]];
            }
            if(i < grid.size() - 1 && grid[i + 1][j] != 0 && visited.find(grid[i + 1][j]) == visited.end())
            {
                visited.insert(grid[i + 1][j]);
                area += cnt[grid[i + 1][j]];
            }
            if(j > 0 && grid[i][j - 1] != 0 && visited.find(grid[i][j - 1]) == visited.end())
            {
                visited.insert(grid[i][j - 1]);
                area += cnt[grid[i][j - 1]];
            }
            if(j < grid[0].size() - 1 && grid[i][j + 1] != 0 && visited.find(grid[i][j + 1]) == visited.end())
            {
                visited.insert(grid[i][j + 1]);
                area += cnt[grid[i][j + 1]];
            }
            maxArea = max(area, maxArea);
        }
    }
    
    return maxArea;
}



int main()
{
    vector<vector<int>> grid   {{0,0,0,0,0,0,0},
                                {0,1,1,1,1,0,0},
                                {0,1,0,0,1,0,0},
                                {1,0,1,0,1,0,0},
                                {0,1,0,0,1,0,0},
                                {0,1,0,0,1,0,0},
                                {0,1,1,1,1,0,0}};

    cout<<largestIsland(grid);


}
