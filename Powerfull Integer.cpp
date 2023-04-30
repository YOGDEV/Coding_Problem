//https://practice.geeksforgeeks.org/problems/d894706c496da5c5a4f45b0360c7f4164c516f83/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int> m;//ordered map...
        for(int i=0;i<n;i++)
        {
            m[intervals[i][0]]++;
            m[intervals[i][1]+1]--;
        }
        
        int ans=-1,ps=0;
        for(auto itr : m)
        {
            if(itr.second>=0)
            {
                ps+=itr.second;
                if(ps>=k)
                ans=itr.first;
            }
            else if(itr.second<0)
            {
                if(ps>=k)
                ans=itr.first-1;
                ps+=itr.second;
            }
        }
        return ans>0?ans:-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
