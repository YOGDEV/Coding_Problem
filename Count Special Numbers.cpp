//https://practice.geeksforgeeks.org/problems/3d49e4cce2820a813da02d1587c2dd9c542ce769/1

//code
try to run this test case for better understanding ...
4
3 14 3 2
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> m;
        for(auto itr : arr)
        m[itr]++;
        
        int ans=0;
        
        for(int i=0;i<N;i++)
        {
            if(m[arr[i]]>1)
            {
                ans++;
                continue;
            }
            else
            {
                int j=0;
                while(j<i)
                {
                    if(arr[i]%arr[j]==0)
                    {
                        ans++;
                        break;
                    }
                    j++;
                }
            }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
