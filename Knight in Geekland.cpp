//https://practice.geeksforgeeks.org/problems/7e5ec07f9d865297cff9a91522c2ce805433b420/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool helper(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        q.push({start_x,start_y});
        
        vector<int> ans;
        vis[start_x][start_y]=1;
        
        int dir1[]={-2,-1,+1,+2,+2,+1,-1,-2};
        int dir2[]={+1,+2,+2,+1,-1,-2,-2,-1};
        
        while(!q.empty())
        {
            int size_q=q.size();
            int value=0;
            
            for(int i=0;i<size_q;i++)
            {
                auto itr=q.front();
                q.pop();
                int first=itr.first;
                int second=itr.second;
                
                 
                value+=arr[first][second];
                
                for(int j=0;j<8;j++)
                {
                    int x=first+dir1[j];
                    int y=second+dir2[j];
                    
                    if(helper(x,y,n,m) and !vis[x][y])
                    {
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            ans.push_back(value);
        }
        
        int maxi=INT_MIN,res=-1;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(i+ans[i]<ans.size())
            ans[i]=ans[i]+ans[i+ans[i]];
        }
        for(int i=0;i<ans.size();i++)
        {
               if(maxi<ans[i])
               {
                   maxi=ans[i];
                   res=i;
               }
        }
        
        return res;
       
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
