//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

//code

 long long mod=1000000007;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isvalid(int x,int y, vector<vector<int>>& grid)
    {
        if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size())return false;
        return true;
    }
    
    long long helper(int x,int y ,vector<vector<int>>& grid , vector<vector<int>>& dp)
    {
        if(dp[x][y]!=-1)return dp[x][y];
        
        long long ans=1;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(isvalid(nx,ny,grid) and grid[x][y]>grid[nx][ny])
            {
                ans=(ans%mod + helper(nx,ny,grid,dp)%mod)%mod;
            }
        }
        return dp[x][y]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        long long cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                cnt=(cnt%mod + helper(i,j, grid, dp)%mod)%mod;
            }
        }
        return (int)cnt%mod;
    }
