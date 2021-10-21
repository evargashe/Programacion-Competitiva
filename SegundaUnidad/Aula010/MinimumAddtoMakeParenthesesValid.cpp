/* https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
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

int minAddToMakeValid(string s) {
    stack<char> stk;
    int count = 0;
    for (char x : s) {
        if (x == '(')
            stk.push(x);
        else {
            if (stk.empty()) {
                count++;
                continue;
            }

            else if (stk.top()!='('  && x == ')')
                count++;

            stk.pop();
        }
    }
    return count+stk.size();
}

int main()
{
    string s="())";
    cout<<minAddToMakeValid(s);

}
