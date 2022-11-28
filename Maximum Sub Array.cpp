//https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1

//code

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int curr_sum=0,max_sum=0;
	    int curr_start=0,max_start=0,max_end=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<0)
	        {   
	            curr_sum=0;
	            curr_start=i+1;
	        }
	        else
	        {
	            curr_sum+=a[i];
	        }
	        
	        if(max_sum<curr_sum)
	        {
	            max_sum=curr_sum;
	            max_start=curr_start;
	            max_end=i+1;
	        }
	        else if(max_sum==curr_sum)
	        {
	            int left_length=i-curr_start+1;
	            int right_length=max_end-max_start;
	            
	            if(left_length>right_length)
	            {
	                max_start=curr_start;
	                max_end=i+1;
	            }
	        }
	       
	    }
	     vector<int> ans;
	        for(int i=max_start;i<max_end;i++)
	        {
	            ans.push_back(a[i]);
	        }
	        
	        if(ans.empty())ans.push_back(-1);
	        
	        return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
