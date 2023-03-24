//https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

//code

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  //or you can use a "#" in palce of first repeating character and while traversing in the string
  //you can skip that '#' character and perform your task...
    void reverse(string & str)
    {
        int i=0,j=str.length()-1;
        while(i<j)
        {
            swap(str[i++],str[j--]);
        }
    }
    string removeReverse(string S) {
        map<char,int> m;
        int n=S.length();
        
        for(int i=0;i<n;i++)
        m[S[i]]++;
        
        int i=0,j=n-1;
        int flag=0;//even reverse
        
        while(i<=j)
        {
            if(flag==0)
            {
                if(m[S[i]]==1)
                {
                    i++;
                }
                else
                {
                  auto itr=m.find(S[i]);
                  itr->second--;
                  S=S.substr(0,i)+S.substr(i+1);
                  i=0;
                  j=S.length()-1;
                  flag=1;
                }
            }
            else
            {
                if(m[S[j]]==1)
                {
                    j--;
                }
                else
                {
                  auto itr=m.find(S[j]);
                  itr->second--;
                  S=S.substr(0,j)+S.substr(j+1);
                  i=0;
                  j=S.length()-1;
                  flag=0;
                }                
            }
           
        }
         if(flag==1)
            reverse(S);
        
        
    //     for(int i=0;i<n;i++)
    //     {   
    //         auto itr=m.find(S[i]);
    //         if(itr->second >1)
    //         {
    //             itr->second--;
    //             string str=S.substr(0,i)+S.substr(i+1);
    //             reverse(str);
    //             S=str;
    //             i=-1;
    //             n=S.length();
    //         }
            
    //   }
        return S;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
