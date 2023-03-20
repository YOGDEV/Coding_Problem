//https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='X')
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dir[]={-1,0,1,0,-1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int r=it.first.first;
            int c=it.first.second;
            int dis=it.second;
            
            if(grid[r][c]=='Y')
            return dis;
            
            for(int i=0;i<4;i++)
            {
                int x=r+dir[i];
                int y=c+dir[i+1];
                
                if(x>=0 and x<N and y>=0 and y<M and vis[x][y]==0)
                {
                    q.push({{x,y},dis+1});
                    vis[x][y]=1;
                }
            }
            
            
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
