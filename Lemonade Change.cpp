//https://practice.geeksforgeeks.org/problems/lemonade-change/1

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector<int> v(20+1,0);
        
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)v[5]++;
            else if(bills[i]==10)
            {
                if(v[5]>=1)
                {
                    v[5]--;
                    v[10]++;
                }else
                return false;
            }
            else if(bills[i]==20)
            {
                if(v[5]>=1 and v[10]>=1)
                {
                    v[5]--;
                    v[10]--;
                }
                else if(v[5]>=3)
                {
                    v[5]-=3;
                }
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
