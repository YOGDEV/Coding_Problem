//https://practice.geeksforgeeks.org/problems/5877fde1c8e1029658845cd4bc94066ac1d4b09b/1

//code

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> ans;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        
        long long  prefix[n];
        prefix[0]=temp[0];
        for(int i=1;i<n;i++)prefix[i]=temp[i]+prefix[i-1];
        
        map<long,long>m;
        m[temp[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(m.find(temp[i])==m.end())
            m[temp[i]]=prefix[i]-temp[i];
        }
        
        for(auto itr : arr)
        {
            ans.push_back(m[itr]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
