322. Coin Change

//https://leetcode.com/problems/coin-change/

//code

//first approach 
 int helper(vector<int>& nums,int amount,vector<int>& dp)
    {
        if(amount==0)return 0;
        
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int subans=0;
            
            if(amount-nums[i]>=0)
            {
                if(dp[amount-nums[i]]!=-1)subans= dp[amount-nums[i]];
                else
                subans=helper(nums,amount-nums[i],dp);
                if(subans!=INT_MAX and ans>1+subans)
                ans=1+subans;
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-1);
    int res=helper(coins,amount,dp);
    return res==INT_MAX?-1:res;
    }

//second approach
int helper(vector<int>& nums,int amount,int i,vector<vector<int>>& dp)
    {
        if(i>=nums.size())return INT_MAX/2;
        if(amount==0)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=INT_MAX/2;
        
        
        if(amount>=nums[i])
        take=1+helper(nums,amount-nums[i],i,dp);
        int not_take=helper(nums,amount,i+1,dp);
        
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       return INT_MAX/2==helper(coins,amount,0,dp)?-1:helper(coins,amount,0,dp);
    }

//third tabulation method
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size()+1;
        int n=amount+1;
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=1;i<n;i++)dp[0][i]=INT_MAX-1;
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(coins[i-1]>j)dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return INT_MAX-1==dp[m-1][n-1]?-1:dp[m-1][n-1];
    }
