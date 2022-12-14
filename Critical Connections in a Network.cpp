//https://leetcode.com/submissions/detail/859094754/

//code

class Solution {
public:
    int timer=1;
    
    void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &tin,vector<int>& low,vector<vector<int>> & ans)
    {
        vis[node]=1;
        low[node]=tin[node]=timer++;
        
        for(int it:adj[node])
        {
            if(it==parent)continue;
            
            if(vis[it]==0)
            {
                dfs(it,node,adj,vis,tin,low,ans);
                
                low[node]=min(low[node],low[it]);
                
                if(low[it]>tin[node])
                    ans.push_back({node,it});
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,vis,tin,low,ans);
            }
        }
        return ans;
    }
};
