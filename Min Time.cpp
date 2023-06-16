//https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1

//code

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    unordered_map<int,int> m1,m2;
    long long helper(int pos,int ind,vector<int>& temp,vector<vector<long long >>& dp,int indicator)
    {
        if(ind>=temp.size())return 0;
        long long  one=0,two=0;
        
        if(dp[ind][indicator]!=-1)return dp[ind][indicator];
        
        int left=m1[temp[ind]];
        int right=m2[temp[ind]];
        
        one=abs(pos-left)+abs(left-right)+helper(right,ind+1,temp,dp,1);
        if(ind==temp.size()-1)one+=abs(right-0);
        two=abs(pos-right)+abs(left-right)+helper(left,ind+1,temp,dp,0);
        if(ind==temp.size()-1)two+=abs(left-0);
        
        return dp[ind][indicator]=min(one,two);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
       m1.clear();
       m2.clear();
       
       int mx=*max_element(types.begin(),types.end());
       vector<int> ele(mx+1,0);
       
       for(int i=0;i<n;i++)
       {
           ele[types[i]]=1;
           if(m1.find(types[i])==m1.end())
           {
               m1[types[i]]=locations[i];
               m2[types[i]]=locations[i];
           }
           else
           {
               m1[types[i]]=min(m1[types[i]],locations[i]);
               m2[types[i]]=max(m2[types[i]],locations[i]);
           }
       }
       vector<int> temp;
       for(int i=0;i<mx+1;i++)
       if(ele[i]==1)temp.push_back(i);
       vector<vector<long long >> dp(temp.size(),vector<long long >(2,-1));
       return helper(0,0,temp,dp,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
