
/* https://leetcode.com/problems/asteroid-collision/
 */

#include <bits/stdc++.h>


using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    for(auto x : asteroids)
    {
        if(x > 0) 
            res.push_back(x);
        else
        {
            while(res.size() && res.back() > 0 && res.back() < -x) 
                res.pop_back();
            if(res.size() && res.back() == -x) 
                res.pop_back();
            else if(res.empty() || res.back() < 0) 
                res.push_back(x);
        }
    }
    return res;
}
int main()
{

    vector<int> asteroids{5,10,-5};
    vector<int> s=asteroidCollision(asteroids);
    for(int a: s){
        cout<<a<<" ";
    }
    return 0;
}