/* https://leetcode.com/problems/score-of-parentheses/
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

int scoreOfParentheses(string s) {
    int ans = 0;
    int d = -1;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='(')
            d+=1;
        else{
            d+=-1;
        }
        if (s[i] == '(' && s[i + 1] == ')')
            ans += 1 << d;
    }
    return ans;
}

int main()
{
    string s="(()(()))";
    cout<<scoreOfParentheses(s);

}
