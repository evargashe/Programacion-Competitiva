
/* leetcode.com/problems/number-of-enclaves
 */

#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>>&grid,  int row , int col, bool &ans, int &x){
    if((row==grid.size()-1 || row==0 || col==grid[0].size()-1 || col==0) && (grid[row][col]==1)  ){
        ans = true;
        return ;
    }
    if(grid[row][col]!=1) 
        return ;
    x++;
    grid[row][col] = 0;
    dfs(grid , row -1, col , ans,x);
    dfs(grid , row , col-1 , ans,x);
    dfs(grid , row+1 , col , ans,x);
    dfs(grid , row , col+1 , ans,x);
    
    
}

int numEnclaves(vector<vector<int>>& grid) {
    int c=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            bool ans = false;
            int x = 0;
            if(grid[i][j] ==1){
                dfs(grid , i , j , ans , x);
                
            }
            if(ans == false) c+=x;
        }
    }
    return c;
}


int main()
{

    vector<vector<int>> grid{
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };

    cout<<numEnclaves(grid);
}