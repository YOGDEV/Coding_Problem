//https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>> data;
        for(int i=0;i<N;i++)
        {  
            data.push_back({make_pair(S[i],F[i]),i});
        }
        
        sort(data.begin(),data.end());
        
        // for(int i=0;i<N;i++)
        // cout<<data[i].second<<" "<<data[i].first.first<<" "<<data[i].first.second<<endl;
        
        
        int l=data[0].first.first;
        int h=data[0].first.second;
        vector<int> v;
        v.push_back(data[0].second+1);
        for(int i=1;i<N;i++)
        {
            int x=data[i].first.first;
            int y=data[i].first.second;
            int ind=data[i].second;
            
            if(x>=l and y<h)
            {
                v.pop_back();
                v.push_back(ind+1);
                l=x;
                h=y;
            }
            else if(x>h){
            v.push_back(ind+1);
            l=x;
            h=y;
            }
            
        }
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
