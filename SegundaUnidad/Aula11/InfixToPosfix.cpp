/* 


https://www.urionlinejudge.com.br/judge/en/problems/view/1077



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
int Peso(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c== '/')
        return 2;
    else if(c=='+' || c== '-')
        return 1;
    else 
        return 0;
}


void InfixToPosfix(string s) {
    stack<char> stk;

    string cadena;

    for( char c : s )
    {

        if(isalnum(c))
           cadena+=c;
        else if( c == '(')
            stk.push('(');
        else if( c == ')')
        {
            while(stk.top()!='(')
            {
                cadena+=stk.top();
                stk.pop();
            }
            stk.pop();     
        }
        else{
            while(!stk.empty()  && Peso(c)<=Peso(stk.top()))
            {
                cadena+=stk.top();
                stk.pop();
            }
            stk.push(c);

        }
        
    }
    while(!stk.empty()) {
		cadena += stk.top();
		stk.pop();
	}
    cout<<cadena<<endl;
}

int main()
{
    int cantidad;
    cin>>cantidad;
    string s;
    for(int i=0;i<cantidad;i++){
        cin>>s;
        InfixToPosfix(s);
    }
    

}
