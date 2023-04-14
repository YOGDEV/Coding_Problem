//https://practice.geeksforgeeks.org/problems/546ea68f97be7283a04ddcc8057e09b46a686471/1

//code

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>> st;
        st.push({color[0],radius[0]});
        
        for(int i=1;i<N;i++)
        {
            if(!st.empty())
            {
                int first=st.top().first;
                int second=st.top().second;
                
                if(first==color[i] and second==radius[i])
                {
                   st.pop();
                   continue;
                }
            }
            st.push({color[i],radius[i]});
        }
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
