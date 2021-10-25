
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

using namespace std;


void merge(vector<vector<int>> a)
{
    priority_queue<int, vector<int>,
                                greater<int> > g;

    for(int i=0 ; i< a.size(); i++)
    {
        for(int j=0 ; j<a[i].size(); j++)
        {
            g.push(a[i][j]);
        }
    }

    while(!g.empty())
    {
        cout<< g.top()<<" ";
        g.pop();
    }
}

int main()
{
    vector<vector<int>> v{{1,4,5},{1,3,4},{2,6}};
    merge(v);
    return 0;
}
