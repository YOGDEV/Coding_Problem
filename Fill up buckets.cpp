//https://practice.geeksforgeeks.org/problems/fill-up-buckets3500/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        long mod=1000000007;
        long ans=1;
        sort(capacity.begin(),capacity.end());
        
        for(int i=0;i<capacity.size();i++)
        {
            ans=(ans*(capacity[i]-i))%mod;
        }
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
