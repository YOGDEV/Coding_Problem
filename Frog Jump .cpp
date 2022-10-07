//code

#include <bits/stdc++.h> 
int f(int ind,vector<int> &h,vector<int>& dp)
{
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=f(ind-1,h,dp)+abs(h[ind]-h[ind-1]);
    int right=INT_MAX;
    if(ind>1)
        right=f(ind-2,h,dp)+abs(h[ind]-h[ind-2]);
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{  vector<int> dp(n,-1);
    return f(n-1,heights,dp);
}
