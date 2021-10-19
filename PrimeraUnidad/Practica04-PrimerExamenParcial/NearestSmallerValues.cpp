

/* https://cses.fi/problemset/task/1645/
 */

#include <bits/stdc++.h>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
void funcion(vector<int> a,int len)
{
    int i=1;
    int j=i-1;
    int cero=0;
    for(int i=0;i<len;i++)
    {
        bool es=false;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i]){
                cout<<j+1<<" ";
                es=true;
                break;
            }
        }
        if(es==false)
            cout<<cero<<" ";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    cin>>len;

    vector<int> a;
    int dato;
    for(int i=0 ; i<len ;i++)
    {
        cin>>dato;
        a.push_back(dato);
    }
    funcion(a,len);

}