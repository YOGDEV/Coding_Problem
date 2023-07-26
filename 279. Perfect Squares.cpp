//https://leetcode.com/problems/perfect-squares/

//code


int arr[100];
    int helper(int i,int j,int num,vector<vector<int>>& dp)
    {
        if(i>j or num<0)return INT_MAX-1;
        if(num==0)return 0;
        
        if(dp[i][num]!=-1)return dp[i][num];
        
        int not_take=helper(i+1,j,num,dp);
        int take=1+helper(i,j,num-arr[i],dp);
        
        
        return dp[i][num]=min(take,not_take);
    }
    int numSquares(int n) {
        
        for(int i=1;i<=100;i++)
            arr[i-1]=i*i;
        
        int j=0,num=n;
        while(num)
        {
            if(arr[j]>num)break;
            j++;
        }
        vector<vector<int>> dp(j+1,vector<int>(num+1,-1));
        return helper(0,j-1,n,dp);    
    }
