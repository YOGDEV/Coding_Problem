//https://practice.geeksforgeeks.org/problems/d25f415de2ff3e02134de03e17ad019d723ab2e9/1

//code

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
    long long ans=0;
    stack<char> st;
    
    string s1="pr",s2="rp";
    if(X<Y)
    {
        int temp=X;
        X=Y;
        Y=temp;
        
        string t=s1;
        s1=s2;
        s2=t;
    }
    
    for(int i=S.length()-1;i>=0;i--)
    {
        char curr=S[i],first=s1[0],second=s1[1];
        if(!st.empty() and curr==first and st.top()==second)
        {
            st.pop();
            ans+=X;
        }
        else
        st.push(S[i]);
    }
    
    string str;
    while(st.size()>0)
    {
    str.push_back(st.top());
    st.pop();
    }
    
    for(int i=str.length()-1;i>=0;i--)
    {
        char curr=str[i],first=s2[0],second=s2[1];
        if(!st.empty() and curr==first and st.top()==second)
        {
            st.pop();
            ans+=Y;
        }
        else
        st.push(str[i]);
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
