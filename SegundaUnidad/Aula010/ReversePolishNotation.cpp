/* https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <cmath>
#include <iterator>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include<climits>



using namespace std;



int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for(int i=0;i<tokens.size();i++)
    {
        if(tokens[i]=="+")
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(a+b);

        }
        else if(tokens[i]=="-")
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(b-a);

        }
        else if(tokens[i]=="*")
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(a*b);

        }
        else if(tokens[i]=="/")
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(b/a);
        }
        else{
            stk.push(stoi(tokens[i]));
        }
    } 
    int xx = stk.top();
    return xx;
}


int main()
{
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    
    cout<<evalRPN(tokens);
    return 0;
}
