//https://leetcode.com/problems/number-of-ways-to-earn-points/

//code

ic:
    long long mod=1e9+7;
    int dfs(int i,int t,vector<vector<int>>& types,vector<vector<int>>& dp)
    {
        if(t==0)return 1;
        if(i>=types.size() or t<0)return 0;
        
        if(dp[i][t]!=-1)return dp[i][t];
        
        long long ans=0;
        for(int j=0;j<=types[i][0];j++)
        {
            ans+=dfs(i+1,t-types[i][1]*j,types,dp);
            ans=ans%mod;
        }
        return dp[i][t]=ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return dfs(0,target,types,dp)%mod;
    }
