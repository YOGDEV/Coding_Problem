//https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

//code

 vector<vector<long long >> tabel;
    long long mod=1e9+7;
    
    long long dfs(vector<int>& nums)
    {
        int n=nums.size();
        if(n<=2)return 1;
        
        vector<int>left,right;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long left_res=dfs(left);
        long long right_res=dfs(right);
        
        long long left_len=left.size(),right_len=right.size();
        return (((tabel[n-1][left_len]*left_res)%mod)*right_res)%mod;
    }
    int ncr(int n,int r)
    {
        if(r==0 or r==n)return 1;
        return ncr(n-1,r-1)+ncr(n-1,r);
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        tabel.resize(n+1);
        
        for(int i=0;i<n+1;i++)
        {
            tabel[i]=vector<long long>(i+1,1);
            for(int j=1;j<i;j++)
            {
                // tabel[i][j]=(tabel[i-1][j-1] + tabel[i-1][j])%mod;
                 tabel[i][j]=(ncr(i-1,j-1) + tabel[i-1][j])%mod;
            }
        }
        int ans=dfs(nums);
        return (ans%mod-1)%mod;
    }
