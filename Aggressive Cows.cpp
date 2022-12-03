//https://practice.geeksforgeeks.org/problems/aggressive-cows/1

//code

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int aggressive(vector<int> & stalls,int n,int k,int mid)
    {
        int cows=1;
        int no_stalls=stalls[0];
        
        for(int i=0;i<n;i++)
        {
            
            if(stalls[i]-no_stalls>=mid)
            {
                cows++; 
                no_stalls=stalls[i];
            }
          
        }
        int flag=(cows>=k)? 1:0;
        return flag;
    }
    
    //main function
    int solve(int n, int k, vector<int> &stalls) {
    
    int maximum=INT_MIN;
    sort(stalls.begin(),stalls.end());
    
    for(int i=0;i<n;i++)
    {
        maximum=max(maximum,stalls[i]);
       
    }
    int ans=-1;
    
    int low=0;
    int high=maximum;
    int mid=low+(high-low)/2;
    
    while(low<=high)
    {
      if(aggressive(stalls,n,k,mid))
      {
          ans=mid;
          low=mid+1;
      }
      else
      high=mid-1;
      
      mid=low+(high-low)/2;
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
