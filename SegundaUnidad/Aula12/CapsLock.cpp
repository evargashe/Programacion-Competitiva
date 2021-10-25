
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
    string salida;
    for(int i=0 ; i<s.size() ;i++)
    {
        if(s[i]=='$')
        {
            if(cola.front()=='$')
            {
                cola.pop_front();
                while(!cola.empty())
                {
                    salida+=toupper(cola.front());
                    cola.pop_front();
                }
            }
            else if(cola.empty())
                cola.push_back('$');
            
        }
        else if(cola.front()=='$')
        {
            if( isalpha(s[i]))
                cola.push_back(s[i]);
        }
        else if( cola.empty())
            salida+=s[i];

    }
    for(int i=0 ;i<salida.size(); i++)
        if(isalpha(salida[i]))
            cout<<salida[i]<<" ";
}

int main()
{

    string  cadena;
    cin>>cadena;
    capslock(cadena);
    return 0;

}
