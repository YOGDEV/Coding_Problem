//https://leetcode.com/problems/time-needed-to-inform-all-employees/

//code

//dfs solution
class Solution {
public:
    unordered_map<int,vector<int>> m;
    int ans=0,mx=0;
    
    void dfs(int manager,vector<int>& info)
    {
        mx=max(mx,ans);
        for(auto employee : m[manager])
        {
            ans+=info[manager];
            
            dfs(employee,info);
            
            ans-=info[manager];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
     
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                m[manager[i]].push_back(i);
            }
        }
        dfs(headID,informTime);
        return mx;
    }
};

//bfs Solution

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        queue<int> q;
        int ans =0;
        q.push(headID);
        vector<int> gp[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                gp[manager[i]].push_back(i);
            }
        }
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
            for(auto itr : gp[temp])
            {
                q.push(itr);
                informTime[itr]+=informTime[temp];
                ans=max(ans,informTime[itr]);
            }
        }
        return ans;
    }
};
