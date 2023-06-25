//https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1

//code

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
//User function Template for C++


class Solution{
  struct trie{
  trie* child[26]={nullptr};
  int prefix=0;
  bool istrue=false;
};
trie* root=new trie();
void create( string str)
{
    int n=str.length();
    trie* node=root;
    for(int i=0;i<str.length();i++)
    {
        
        if(node->child[str[i]-'a']==nullptr)
        {
            node->child[str[i]-'a']=new trie();
        }
        
        node=node->child[str[i]-'a'];
        node->prefix++;
    }
    node->istrue=true;
}

int search(string str)
{
    trie* node=root;
    for(int i=0;i<str.length();i++)
    {
        if(node->child[str[i]-'a']==nullptr)return 0;
        node=node->child[str[i]-'a'];
    }
    return node->prefix;
}
public:
    int klengthpref(string arr[], int n, int k, string str){   
        if(k>str.length())
        return 0;
        for(int i=0;i<n;i++)
        create(arr[i]);
        
        return search(str.substr(0,k));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
