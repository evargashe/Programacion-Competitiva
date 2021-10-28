/* https://leetcode.com/problems/kth-largest-element-in-an-array/ */


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

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> g;
    for(int i=0 ; i<nums.size(); i++)
        g.push(nums[i]);
    int it;
    while(k--)
    {
        it=g.top();
        g.pop();
    }
    return it;
}

int main()
{
    vector<int> nums={3,2,1,5,6,4};
    int k=2;
    cout<<findKthLargest(nums,k);
    return 0;

}
