//https://practice.geeksforgeeks.org/problems/santa-banta2814/1

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
   
    vector<int> prime;
    void precompute(){
        vector<bool> isprime(1e6+1,true);
        // isprime[0]=false;
        // isprime[1]=false;
        for(int i=2;i<1e6+1;i++)
        {
            if(isprime[i]==true)
            {
               prime.push_back(i);
               for(int j=2*i;j<1e6+1;j+=i)
               {
                  isprime[j]=false;
               }
            }
        }
    }
    void dfs(int ind,int &cnt,vector<int>& vis,vector<vector<int>>& gp)
    {
        vis[ind]=1;
        cnt++;
        for(int i=0;i<gp[ind].size();i++)
        {
            if(!vis[gp[ind][i]])
            dfs(gp[ind][i],cnt,vis,gp);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
      
      int len=0;
      vector<int> vis(n+1,0);
      for(int i=1;i<=n;i++)
      {
          if(!vis[i])
          {
          int cnt=0;
          
          dfs(i,cnt,vis,g);
          len=max(len,cnt);
          }
      }
       if(len==1)return -1;
       
       return prime[len-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
