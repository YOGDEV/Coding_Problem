//https://leetcode.com/problems/shortest-path-in-binary-matrix/

//code

class Solution {
public:
    int ans=INT_MAX;
    void helper(int i,int j,int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis,int len)
    {
        if(i<0 or j<0 or j>=y+1 or i>=x+1 or vis[i][j] )return ;
        if(grid[i][j]==1)return ;
        if(i==x and j==y and grid[i][j]==0){
            len+=1;
            ans=min(ans,len);
            return;
        }
        
        if(grid[i][j]==0)
        {
            vis[i][j]=1;
            
            helper(i+1,j,x,y,grid,vis,len+1);
            helper(i-1,j,x,y,grid,vis,len+1);
            helper(i,j+1,x,y,grid,vis,len+1);
            helper(i,j-1,x,y,grid,vis,len+1);
            
            helper(i-1,j-1,x,y,grid,vis,len+1);
            helper(i+1,j-1,x,y,grid,vis,len+1);
            helper(i-1,j+1,x,y,grid,vis,len+1);
            helper(i+1,j+1,x,y,grid,vis,len+1);
            vis[i][j]=0;
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        //vector<vector<int>> vis(n,vector<int>(n,0));
        // helper(0,0,n-1,n-1,grid,vis,0);
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;
        queue<pair<int,int>> pq;
        pq.push({0,0});
        
        int dir1[]={-1,-1,0,+1,+1,+1,0,-1};
        int dir2[]={0,+1,+1,+1,0,-1,-1,-1};
        int k=1;
        grid[0][0]=1;
        while(!pq.empty())
        {
            int size=pq.size();
            
            for(int i=0;i<size;i++)
            {
                int first=pq.front().first;
                int second=pq.front().second;
                pq.pop();
                
                for(int j=0;j<8;j++)
                {
                     int x=first+dir1[j];
                     int y=second+dir2[j];
                
                     if(x>=0 and y>=0 and y<n and x<n)
                     {
                        if(grid[x][y]==0)
                        {
                           grid[x][y]=k+1;
                           pq.push({x,y});
                        }
                     }
                 }
                  
            }
            k++;
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<n;j++)cout<<grid[i][j]<<" ";cout<<endl;
            // }
        }
        return grid[n-1][n-1]==0?-1:grid[n-1][n-1];
    }
};
