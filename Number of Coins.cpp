//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

//code

int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=V;i++)
	    {
	        for(int j=0;j<M;j++)
	        {
	            if(coins[j]<=V)
	            {
	                if(i-coins[j]>=0 and dp[i-coins[j]]!=INT_MAX)
	                dp[i]=min(dp[i],1+dp[i-coins[j]]);
	            }
	        }
	    }
	    return dp[V]==INT_MAX?-1:dp[V];
	} 

///////////////////////////////////////////////////////////////////////////////
int helper(int i,int coins[],int m,int v,vector<vector<int>>& dp)
	{
	    if(v==0)return 0;
	    if(dp[i][v]!=-1)return dp[i][v];
	    int ans=INT_MAX-1;
	    for(int ind=0;ind<m;ind++)
	    {
	        if(coins[ind]<=v)
	        ans=min(ans,1+helper(ind,coins,m,v-coins[ind],dp));
	    }
	    return dp[i][v]=ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    int ans=helper(0,coins,M,V,dp);
	    return ans>=INT_MAX/2?-1:ans;
	} 
