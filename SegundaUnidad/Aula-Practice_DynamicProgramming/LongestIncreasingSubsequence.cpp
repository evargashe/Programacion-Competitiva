/* leetcode.com/problems/longest-increasing-subsequence
 */

#include <bits/stdc++.h>

using namespace std;



int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                d[i]=max(d[i], d[j] + 1);
        }
    } 
    return *max_element(d.begin(),d.end());
}
  
int main()
{
    vector<int> nums{10,9,2,5,3,7,101,18};

    cout<<lengthOfLIS(nums);
    return 0;
}