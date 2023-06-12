//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//code

int helper(int ind,vector<int>& price,int n,vector<vector<int>>& dp)
{
	if(ind==0)return price[ind]*n;
    if(dp[ind][n]!=-1)return dp[ind][n];

	int not_take=helper(ind-1,price,n,dp);
	int take=-1;
	int rodlen=ind+1;
	if(rodlen<=n)
	take=price[ind]+helper(ind,price,n-rodlen,dp);

	return dp[ind][n]=max(take,not_take);
}
int cutRod(vector<int> &price, int n)
{
   
   vector<int>prev(n+1,0),curr(n+1,0);
   for(int N=0;N<=n;N++)prev[N]=N*price[0];

   for(int ind=1;ind<n;ind++)
   {
	   for(int N=0;N<=n;N++)
	   {
          int not_take=prev[N];
	      int take=-1;
	      int rodlen=ind+1;
	      if(rodlen<=N)
	      take=price[ind]+curr[N-rodlen];

	      curr[N]=max(take,not_take);
	   }
	   prev=curr;
   }
   return prev[n];
}
