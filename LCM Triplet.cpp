//https://practice.geeksforgeeks.org/problems/lcm-triplet1501/1

//code

//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int gcd(int a,int  b)
    {
        if(b==0)return a;
        
        return gcd (b,a%b);
    }
    long long lcmTriplets(long long N) {
          if(N==1 || N==2)
          {
              return N;
          }
          if(N==3)return 6;
          long long ans=0;
          if(N%2!=0)
          {
              ans=N*(N-1)*(N-2);
          }
          else
          {
              if(gcd((int)N,(int)(N-3))==1)
              {
                  ans=N*(N-1)*(N-3);
              }
              else
              {
                  ans=(N-1)*(N-2)*(N-3);
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
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends
