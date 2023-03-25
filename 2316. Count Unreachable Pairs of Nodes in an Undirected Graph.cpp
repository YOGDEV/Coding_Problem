//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

//code

1...//brute force tle solution (n^2)
  
 class Solution {
public:
    vector<int> parent,rank;
    
    int find(int x)
    {
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    
    void union_(int x,int y)
    {
        int a=find(x);
        int b=find(y);
        
        if(a==b)return;
        else if(rank[a]>rank[b])
            parent[b]=a;
        else if(rank[a]<rank[b])
            parent[a]=b;
        else
        {
            parent[a]=b;
            rank[b]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {

        int ans=0;
        parent.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        rank.resize(n,0);
               
        for(auto itr : edges)
        {
            int first=itr[0];
            int second=itr[1];
            
            if(find(first)!=find(second))
                union_(first,second);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(find(i)!=find(j))ans++;
            }
        }
        
        return ans;
    }
};


//optimized solution with tc(n) using dfs

class Solution {
public:
    #define ll long long
    void dfs(int i,vector<int> &vis,vector<vector<int>>& adj,ll &cnt)
    {
        vis[i]=1;
        cnt++;
        for(int itr : adj[i])
        {
            if(vis[itr]==0)
            dfs(itr,vis,adj,cnt);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(auto itr : edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int> vis(n,0);
        
        ll ans=((ll)n*(n-1))/2;//remember here you should keep in mind the integer limit..
        for(int i=0;i<n;i++)
        {
            ll cnt=0;
            if(vis[i]==0)
            {
                dfs(i,vis,adj,cnt);
                ans-=((ll)cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};
