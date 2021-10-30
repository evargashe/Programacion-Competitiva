/* https://open.kattis.com/problems/integerlists */


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

void solution(int N)
{
    int len;
    string operacion,cadena;
    while(N--)
    {
        cin>>operacion;
        cin>>len;
        cin>>cadena;

        deque<int> stk;
        for (int i=0 ; i<cadena.size();i++)
        {
            string aux;
            int j=i;
            while(cadena[j]>='0' && cadena[j]<='9')
            {

                aux+=cadena[j];
                j++;
            }
            if(aux.size()>0)
            {
                stk.push_back(stoi(aux, nullptr, 0));
            }
            i=j;
        }
        bool verificar=true;
        bool error=false;
        for(int i=0 ; i<operacion.size(); i++)
        {
            if(operacion[i]=='R')
            {
                verificar=!verificar;
            }
            else
            {
                if(stk.size()==0)
                {
                    error=true;
                    break;
                }

                if(verificar)
                {
                    stk.pop_front();
                }
                else{
                    stk.pop_back();
                }
                
            }
        }
        if(error) 
            cout<<"error"<<endl;
        else if(!error)
        {

            cout<<"[";
            while(!stk.empty())
            {
                if(verificar) {
                    cout << stk.front();
                    stk.pop_front();
                }
                else {
                    cout << stk.back();
                    stk.pop_back();
                }

                if(stk.size() != 0) {
                    cout << ",";
                }
            }
            cout << "]" << endl;

        }


    }

}
int main()
{
    int N;
    cin>>N;
    solution(N);
    return 0;

}
