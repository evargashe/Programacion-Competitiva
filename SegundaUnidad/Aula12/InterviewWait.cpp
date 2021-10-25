
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


int interviewWait(vector<int> s)
{
    deque<int> cola;

    for( int i=0 ; i< s.size(); i++)
        cola.push_back(s[i]);
    int a=0;
    while(cola.front()!=-1 && cola.back()!=-1)
    {
        if(cola.front()> cola.back())
        {
            a+=cola.back();
            cola.pop_back();
        }
        else{
            a+=cola.front();
            cola.pop_front();
        }
    }
    return a;
}

int main()
{

    vector<int>  cadena{4,-1,5,2,3};
    cout<<interviewWait(cadena);
    return 0;

}
