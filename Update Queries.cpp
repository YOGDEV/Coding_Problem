//https://practice.geeksforgeeks.org/problems/a6528c893d4ab645ec6e0690c7982748385099c8/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<int> ans(N,0);
            vector<vector<int>> prefix(N+1,vector<int>(32,0));
            
            for(int i=0;i<Q;i++)
            {
                int l=U[i][0];
                int r=U[i][1];
                int x=U[i][2];
                
                int pos=0;
                while(x>0)
                {
                    if(x&1!=0)//last bit is 1
                    {
                        prefix[l-1][pos]++;
                        prefix[r][pos]--;
                    }
                    x/=2;//x>>2 right shift
                    pos++;
                }
            }
            
            for(int i=0;i<32;i++)//travesting in column
            {
                for(int j=1;j<N;j++)//traversing in row
                {
                    prefix[j][i]+=prefix[j-1][i];
                }
            }
            
           
            
            for(int i=0;i<N;i++)
            {
               int res=0;
               for(int j=0;j<32;j++)
               {
                   if(prefix[i][j]>0)
                   {
                       res+=(1<<j);
                   }
               }
               ans[i]=res;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
