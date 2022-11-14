//https://practice.geeksforgeeks.org/problems/find-patterns0606/1

//code

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        vector<bool> visited(S.length(),false);
        
        int j,k,ans=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]==W[0] && !visited[i])
            {
                visited[i]=true;
                j=i+1;
                k=1;
                while(j<S.length() && k<W.length())
                {
                    if(S[j]==W[k] && !visited[j]){
                    visited[j]=true;
                    k++;
                    }
                    j++; 
                    
                }
                if(k==W.length())
                ans++;
                else
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends
