/* https://open.kattis.com/problems/teque */


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


/*
9
push_back 9
push_front 3
push_middle 5
get 0
get 1
get 2
push_middle 1
get 1
get 2
*/


void solution(int N)
{
    deque<int> stk;
    deque<int> salida;
    while(N--)
    {
        string s;
        int dato;
        cin>>s;cin>>dato;

        if(s=="push_back")
        {
            stk.push_back(dato);
        }
        else if(s=="push_front")
        {
            stk.push_front(dato);
        }
        else if(s=="push_middle"){
            int tam=(stk.size()+1)/2;
            auto it = stk.begin()+tam; // 3 5 9
            stk.insert(it,dato);
        }
        else if(s=="get")
        {
            auto it = stk.begin()+dato;
            salida.push_back(*it);
        }

    }
    while(!salida.empty())
    {
        cout<<salida.front()<<endl;
        salida.pop_front();
    }
}

int main()
{
    int N;
    cin>>N;
    solution(N);
    return 0;

}
