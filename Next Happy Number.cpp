Next Happy Number

//https://practice.geeksforgeeks.org/problems/next-happy-number4538/1

//code

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int helper(int N)
    {
        if(N==1 or N==7)return 1;
        
        int sum=N,curr=N;
        
        while(sum>9)
        {
            sum=0;
            
            while(curr>0)
            {
                int sq=curr%10;
                sum+=(sq*sq);
                curr/=10;
            }
            curr=sum;
        }
        if(sum==1 or sum==7)return 1;
        return 0;
    }
    int nextHappy(int N){
        int next=N+1;
        while(1)
        {
            if(helper(next))
            return next;
            next++;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
