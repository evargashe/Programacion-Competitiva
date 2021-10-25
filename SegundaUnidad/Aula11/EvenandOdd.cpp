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

void evenandodd(int n,vector<int> asc,vector<int> desc)
{
    sort(asc.begin(),asc.end());
    sort(desc.rbegin(),desc.rend());


    for(auto itr=asc.begin(); itr!=asc.end();itr++)
        cout<<*itr<<endl;
    for(auto itr=desc.begin(); itr!=desc.end();itr++)
        cout<<*itr<<endl;

}


int main()
{
    int n;
    cin>>n;

    vector<int> asc;
    vector<int> desc;
    int dato;
    for(int i=0;i<n;i++)
    {
        cin>>dato;
        if(dato%2==0)
            asc.push_back(dato);
        else
            desc.push_back(dato);

    }
    evenandodd(n,asc,desc);
    return 0;

}
