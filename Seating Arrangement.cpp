//https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int c=0;
        for(int i=0;i<m;i++)
        {
            if(seats[i]==0)
            {
                if(i==0)
                {
                    if(seats[1]==0){
                    seats[i]=1;
                    c++;}
                }
                else if(i==m-1)
                {
                    if(seats[i-1]==0){
                    seats[i]=1;
                    c++;}
                }
                else
                {
                    if(seats[i-1]==0 and seats[i+1]==0){
                    seats[i]=1;
                    c++;}
                }
            }
        }
        return c>=n;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends
