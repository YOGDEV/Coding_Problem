//https://practice.geeksforgeeks.org/problems/63c232252d445a377e01cd91adfd7d1060580038/1

//code

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
      map<int,int> m;
      
      for(vector<int>& x:lines)
      {
          int st=x[0],end=x[1]+1;
          
          m[st]++;
          m[end]--;
      }
      int ans=1,curr=0;
      for(auto itr : m)
      {
          curr+=itr.second;
          ans=max(ans,curr);
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
