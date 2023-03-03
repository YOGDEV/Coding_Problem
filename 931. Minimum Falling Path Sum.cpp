//https://leetcode.com/problems/minimum-falling-path-sum/

//code
//memoization

 int helper(int i,int j,int n,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        if(j<0 || j>=n)return 1e8;

        if(i==0)return mat[0][j];//base case
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=mat[i][j] + helper(i-1,j-1,n,mat,dp);
        int b=mat[i][j] + helper(i-1,j,n,mat,dp);
        int c=mat[i][j] + helper(i-1,j+1,n,mat,dp);
        
        return dp[i][j]=min(a,min(b,c));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
           ans=min(ans,helper(n-1,i,n,matrix,dp));
        } 
        return ans;
    }
