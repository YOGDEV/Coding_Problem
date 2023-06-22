122. Best Time to Buy and Sell Stock II

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//code

int helper(int i,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i==prices.size())return 0;
        
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        
        if(buy==1)
        {
            profit=max(-prices[i]+helper(i+1,0,prices,dp),0+helper(i+1,1,prices,dp));
        }
        else
        {
            profit=max(prices[i]+helper(i+1,1,prices,dp),0+helper(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
