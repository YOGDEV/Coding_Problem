https://practice.geeksforgeeks.org/contest/graphic-era-university-placement-assessment-test/problems

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    long long helper(int s,int d,int n,vector<vector<pair<long long,long long>>>& gp)
    {
        vector<long long > dist(2*n,1e18);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,s});
        dist[s]=0;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            long long node=it.second;
            
            for(auto itr:gp[node])
            {
                long long adjnode=itr.first;
                long long adjdis=itr.second;
                
                if(dis+adjdis<dist[adjnode])
                {
                    dist[adjnode]=dis+adjdis;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return min(dist[d],dist[d+n]);
    }
    long long minTime(int n, int X, int src, int dest, int M1, int M2,
                vector<vector<int>> airlines, vector<vector<int>> railways){
        vector<vector<pair<long long,long long>>> gp(2*n);
        for(auto itr:airlines)
        {
            gp[itr[0]].push_back({itr[1],itr[2]});
        }
        for(auto itr:railways)
        {
            gp[itr[0]+n].push_back({itr[1]+n,itr[2]});
        }
        
        for(int i=0;i<n;i++)
        {
            gp[i].push_back({i+n,X});
            gp[i+n].push_back({i,X});
        }
        long long  ans=1e18;
        ans=min(ans,helper(src,dest,n,gp));
        ans=min(ans,helper(src+n,dest,n,gp));
        
        return ans==1e18?-1:ans;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X, src, dest;
        cin >> N >> X;
        cin >> src >> dest;
        int M1, M2;
        cin >> M1;
        vector<vector<int>> airlines(M1, vector<int> (3));
        for(int i = 0; i < M1; i++){
            cin >> airlines[i][0] >> airlines[i][1] >> airlines[i][2];
        }
        cin >> M2;
        vector<vector<int>> railways(M2, vector<int> (3));
        for(int i = 0; i < M2; i++){
            cin >> railways[i][0] >> railways[i][1] >> railways[i][2];
        }
        Solution obj;
        cout << obj.minTime(N, X, src, dest, M1, M2, airlines, railways) << "\n";
    }
}

// } Driver Code Ends
