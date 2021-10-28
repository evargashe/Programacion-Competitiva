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
void backSpace(string s)
{
    deque<char> stk;
    for(char a: s)
    {
        if(isalpha(a))
            stk.push_back(a);
        else{
            stk.pop_back();
        }
    }
    while(!stk.empty())
    {
        cout<<stk.front();
        stk.pop_front();
    }
   
}

int main()
{

    string  cadena;
    cin>>cadena;
    backSpace(cadena);
    return 0;

}