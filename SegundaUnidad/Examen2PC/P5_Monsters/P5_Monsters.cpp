/* 
https://cses.fi/problemset/task/1194
 */
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    char s[1005][1005];
    char path[1005][1005];
    int n , m;
    cin >> n >> m;
    int x1 , y1;
    queue < pair <int , int> > q;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
        cin >> s[i][j];
        if(s[i][j] == 'A')
        {
            x1 = i;
            y1 = j;
        }
        else if(s[i][j] == 'M')
        {
            q.push({i,j});
        }
        }
    }
    q.push({x1,y1});
    if(x1 ==0 || x1==n-1 || y1 == 0 || y1 == m-1)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(s[x][y] == 'M')
        {
            if(x+1>=0 && x+1<n && y>=0 && y<m && s[x+1][y] == '.')
            {
                s[x+1][y] = 'M';
                q.push({x+1,y});
            }
            if(x-1>=0 && x-1<n && y>=0 && y<m && s[x-1][y] == '.')
            {
                s[x-1][y] = 'M';
                q.push({x-1,y});
            }
            if(x>=0 && x<n && y-1>=0 && y-1<m && s[x][y-1] == '.')
            {
                s[x][y-1] = 'M';
                q.push({x,y-1});
            }
            if(x>=0 && x<n && y+1>=0 && y+1<m && s[x][y+1] == '.')
            {
                s[x][y+1] = 'M';
                q.push({x,y+1});
            }
        }
        else if(s[x][y] == 'A')
        {
            if(x ==0 || x==n-1 || y == 0 || y == m-1)
            {
                string ans;
                while(x!=x1 || y!=y1)
                {
                    ans = path[x][y]+ans;
                    if(path[x][y] == 'D') 
                        x--;
                    else if(path[x][y]=='U') 
                        x++;
                    else if(path[x][y]=='R') 
                        y--;
                    else  
                        y++;
                }
            
                cout<<"YES"<< endl;
                cout<<ans.length()<<endl;
                cout<< ans<< endl;
                return 0;
            }
            if(x+1>=0 && x+1<n && y>=0 && y<m && s[x+1][y] == '.') 
            { 
                path[x+1][y] = 'D';
                q.push({x+1,y}); s[x+1][y] = 'A';
            }
            if(x-1>=0 && x-1<n && y>=0 && y<m && s[x-1][y] == '.') 
            { 
                path[x-1][y] = 'U';
                q.push({x-1,y}); s[x-1][y] = 'A';
            }
            if(x>=0 && x<n && y+1>=0 && y+1<m && s[x][y+1] == '.') 
            { 
                path[x][y+1] = 'R';
                q.push({x,y+1}); s[x][y+1] = 'A';
            }
            if(x>=0 && x<n && y-1>=0 && y-1<m && s[x][y-1] == '.') 
            { 
                path[x][y-1] = 'L';
                q.push({x,y-1}); s[x][y-1] = 'A';
            }
        }
    }
    cout<< "NO"<< endl;
}