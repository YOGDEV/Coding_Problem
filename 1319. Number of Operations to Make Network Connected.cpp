//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

//code

class Solution {
public:
    vector<int> rank,parent;
    int find(int x)
    {
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    void union_(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        
        if(x==y)return ;
        else if(rank[x]<rank[y])
            parent[x]=y;
        else if(rank[x]>rank[y])
            parent[y]=x;
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        
        int extra_edges=0;
        for(auto itr : connections)
        {
            if(find(itr[0])==find(itr[1]))
            {
                extra_edges++;
            }
            else
            {
                union_(itr[0],itr[1]);
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
            if(parent[i]==i)cnt++;
        
        int ans=cnt-1;
        if(extra_edges>=ans)
            return ans;
        return -1;
    }
};
