//https://leetcode.com/problems/detonate-the-maximum-bombs/

//code

class Solution {
public:
    void dfs(int &cnt,int i,vector<int> gp[],vector<bool>& vis)
    {
        vis[i]=true;
        cnt++;
        for(auto itr : gp[i])
        {
            if(!vis[itr])dfs(cnt,itr,gp,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=-1;
        int n=bombs.size();
        vector<int> gp[n];
        for(int i=0;i<n;i++)
        {
            long long int  x1=bombs[i][0];
            long long int  y1=bombs[i][1];
            long long int  r1=bombs[i][2];
            
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long int x=abs(x1-bombs[j][0]);
                    long long int y=abs(y1-bombs[j][1]);
                    if((x*x+y*y)<= r1*r1)
                        gp[i].push_back(j);
                }
            }
            for(int i=0;i<n;i++)
            {
                int cnt=0;
                vector<bool> vis(n,false);
                dfs(cnt,i,gp,vis);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
