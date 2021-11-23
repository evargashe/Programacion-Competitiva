/* https://leetcode.com/problems/keys-and-rooms/ */


#include <bits/stdc++.h>

using namespace std;


void dfs(int x , vector<vector<int>> &a, vector<int> &vis) {
        vis[x] = true;
        for(int to : a[x]) {
            if(!vis[to]) {
                dfs(to,a,vis);
            }
        }
    }
bool canVisitAllRooms(vector<vector<int>>& rooms) {

    vector<vector<int>> a;

    vector<int> vis;
    a = rooms;
    
    int n = a.size();
    vis.resize(n);
    dfs(0,a,vis);
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            return false;
        }
    }
    return true;
}

int main()
{

    vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};


    cout<<canVisitAllRooms(rooms);


    return 0;
}
