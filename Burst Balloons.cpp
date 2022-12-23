//https://practice.geeksforgeeks.org/problems/burst-balloons/1

//code

 
    int maxCoins(int N, vector<int> &arr) {
        
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        
        int n=arr.size();
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        return solve(arr,dp,0,n-1);
    }
    int solve(vector<int>& v,vector<vector<int>> &dp,int s,int e)
    {
        if(e-s==1)return 0;
        
        if(dp[s][e]!=-1)return dp[s][e];
        
        int ans=0;
        for(int m=s+1;m<e;m++)
        {
            int curr=v[s]*v[m]*v[e] + solve(v,dp,s,m) + solve(v,dp,m,e);
            ans=max(ans,curr);
        }
        return dp[s][e]=ans;
    }
