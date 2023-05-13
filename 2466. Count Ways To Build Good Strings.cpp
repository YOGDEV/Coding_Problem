//https://leetcode.com/problems/count-ways-to-build-good-strings/

//code

class Solution {
public:
    int mod=1000000007;
    int helper(int target,int zero,int one,vector<int>& dp)
    {
        if(target==0)return 1;
        if(target<0)return 0;
        
        if(dp[target]!=-1)return dp[target];
        
        long long sum=0;
        sum+=helper(target-zero,zero,one,dp)+helper(target-one,zero,one,dp);
        return dp[target]=sum%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int> dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            ans=(ans%mod)+(helper(i,zero,one,dp)%mod);
        }
        return ans%mod;
    }
};
