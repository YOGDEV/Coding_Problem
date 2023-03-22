//https://leetcode.com/problems/number-of-zero-filled-subarrays/

//code

class Solution {
public:
    #define ll long long 
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        int count=0;
        for(auto num :nums)
        {
            if(num==0)
            {
                ans+=++count;
            }
            else
            {
                count=0;
            }
        }
        return ans;
    }
};
