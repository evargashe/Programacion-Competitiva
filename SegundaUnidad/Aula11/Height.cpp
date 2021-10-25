/*

https://app.codility.com/programmers/lessons/7-stacks_and_queues/

https://www.urionlinejudge.com.br/judge/en/problems/view/1077

https://www.urionlinejudge.com.br/judge/en/problems/view/1259

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
    int i;
    while(n--)
    {
        scanf("%d",&tam);
        vector<int> a(tam);
        for(int j=0 ; j< tam ; j++)
        {
            scanf("%d",&a[j]);
        }
        sort(a.begin(),a.end());
        for(i=0 ; i< a.size()-1; i++)
            printf("%d ",a[i]);
        printf("%d",a[tam-1]);
        printf("\n");
        a.clear();
    }

}
