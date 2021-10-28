/*

https://www.urionlinejudge.com.br/judge/en/problems/view/1566


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

using namespace std;



/*voi
d height(vector<int> a)
{
    sort(a.begin(),a.end());

    for(auto itr=a.begin(); itr!=a.end();itr++)
        cout<<*itr<<" ";
    cout<<endl;
}*/


int main()
{
    int n;
    scanf("%d",&n);
    int tam;
    priority_queue<int, vector<int>, 
                       greater<int>> g;
    int dato;
    while(n--)
    {
        scanf("%d",&tam);
        for(int j=0 ; j < tam ; j++)
        {
            scanf("%d",&dato);
            g.push(dato);
        }
        while(g.size()>0)
        {
            printf("%d ",g.top());
            g.pop();
        }
        printf("\n");
    }
    return 0;

}
