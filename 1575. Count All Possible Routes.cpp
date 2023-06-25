//https://leetcode.com/problems/count-all-possible-routes/

//code

 long long mod=1e9+7;
    int helper(vector<int>& locations,int current,int finish,int fuel,vector<vector<int>>& dp)
    {
        if(fuel<0)return 0;
        
        if(dp[current][fuel]!=-1)return dp[current][fuel];
        
        int ans=0;
        if(current==finish)ans++;
        for(int next=0;next<locations.size();next++)
        {
            if(next!=current)
            {
                ans=(ans%mod+helper(locations,next,finish,fuel-abs(locations[current]-locations[next]),dp)%mod)%mod;
            }
        }
        return dp[current][fuel] =ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size(),vector<int>(fuel+1,-1));
        return helper(locations,start,finish,fuel,dp)%mod;
    }
