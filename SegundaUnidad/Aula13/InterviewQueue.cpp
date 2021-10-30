/* https://open.kattis.com/problems/interviewqueue */


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


int main()
{
    int N;
    cin>>N;
    int dato;
    deque<int> stk;
    for(int i=0; i<N ;i++)
    {
        cin>>dato;
        stk.push_back(dato);

    }
    
    int i=-1;
    int j=1;
    while(!stk.empty())
    {

        //deque<int>::iterator it=stk.begin()+i;
        deque<int>::iterator it2=stk.begin()+j;
        //cout<<*it<<endl;
        cout<<*it2<<endl;
        stk.front();
        stk.pop_front();
        /* if(i==-1)
        {
            if(*it2>stk.front())
            {
                stk.front();
                stk.pop_front();
                continue;
            }
            else{
                i++;j++;
            }
        }
        else if(j==stk.size()-1)
        {
            if(*it>stk.front())
            {
                stk.front();
                stk.pop_front();
                continue;
            }
            else{
                i++;j++;
            }
        }
        else{
            if(*it>stk.front())
            {
                stk.front();
                stk.pop_front();
                continue;
            }
            else if(*it2>stk.front())
            {
                stk.front();
                stk.pop_front();
                continue;
            }
            else{
                i++;j++;
            }
        } */

    }
    while(!stk.empty())
    {
        cout<<stk.front()<<" ";
        stk.pop_front();
    }

    return 0;

}
