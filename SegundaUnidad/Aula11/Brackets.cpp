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
static vector<char> a {'{','}','[',']','(',')'};

int solution(string &S)
{
    vector<char>::iterator it;
    int esta=0;
    for( int i=0 ; i<S.size(); i++)
    {
        it=find(a.begin(), a.end(), S[i]);
        if (it != a.end())
            
            esta=1;
        else{ 
            esta=0;
            break;
        }
    }
    return esta;
}

int main()
{

    string  cadena;
    cin>>cadena;


    cout<<solution(cadena);
    return 0;

}
