
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
void capslock(string s)
{
    deque<char> cola;
    for(int i=0 ; i<s.size(); i++)
    {
        if(s[i]=='#')
            cola.pop_back();
        else{
            cola.push_back(s[i]);
        }
    }

    while(!cola.empty())
    {
        cout<<cola.front()<<" ";
        cola.pop_front();
    }
}
int main()
{

    string  cadena;
    cin>>cadena;
    capslock(cadena);
    return 0;

}
