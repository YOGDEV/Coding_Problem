//https://leetcode.com/problems/maximal-square/

//code

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        int res=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(i==0 || j==0)
                {
                    if(matrix[i][j]=='1')
                    dp[i][j]=1;
                }
                else if(matrix[i][j]=='1')
                {
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                   
                }
                res=max(res,dp[i][j]);
            }
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return res*res;
    }
