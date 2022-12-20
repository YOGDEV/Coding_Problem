//https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];
        for(auto itr : edges)
        {
            adj[itr[0]].push_back({itr[1],itr[2]});
            adj[itr[1]].push_back({itr[0],itr[2]});
        }
        
        vector<int> parent(n+1),dist(n+1,INT_MAX);
        for(int i=1;i<=n;i++)parent[i]=i;
        
        dist[1]=0;
        
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        while(!pq.empty())
        {
          int node=pq.top().second;
          int dis=pq.top().first;
          pq.pop();
          
          for(auto itr : adj[node])
          {
              int adjNode=itr.first;
              int w=itr.second;
              
              if(dis + w < dist[adjNode])
              {
                  dist[adjNode]=dis + w;
                  pq.push({dist[adjNode],adjNode});
                  parent[adjNode]=node;
              }
              
          }
        }
        if(dist[n]==INT_MAX)return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
