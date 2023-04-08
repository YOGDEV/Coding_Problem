//https://practice.geeksforgeeks.org/problems/badefd58bace4f2ca25267ccfe0c9dc844415e90/1

//code

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> ans;
        if(arr.size()==0)return ans;
        stack<int> st;
        
        st.push(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(!st.empty())
            {
                if((st.top()*arr[i]==0 and st.top()+arr[i]<0) || (st.top()*arr[i]<0) )
                st.pop();
                else 
                st.push(arr[i]);
            }
            else
            st.push(arr[i]);
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends
