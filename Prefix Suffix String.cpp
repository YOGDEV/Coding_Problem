//https://practice.geeksforgeeks.org/problems/5be83263c7f2cb866c60b23b73bb38f88de2461c/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
struct Node{
  Node* child[26];
  bool istrue;
};

Node* getnode(void)
{
    Node *curr=new Node();
    curr->istrue=false;
    
    for(int i=0;i<26;i++)
    curr->child[i]=nullptr;
    
    return curr;
}

void insert(Node *root , string str)
{
    Node *curr=root;
    for(int i=0;i<str.length();i++)
    {
        int ind=str[i]-'a';
        if(!curr->child[ind])
        curr->child[ind]=getnode();
        
        curr=curr->child[ind];
    }
    curr->istrue=true;
}

bool search(Node* root,string str,int ind)
{
  bool ans=false;
  if(str.length()==ind)return true;
  
  if(root->child[str[ind]-'a']==nullptr)
  {
      return false;
  }
  else
  {
      ans=ans or search(root->child[str[ind]-'a'],str,ind+1);
  }
  return  ans;
}
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
     
     Node* root=getnode();
     for(auto itr : s1)
     {
     insert(root,itr);
     reverse(itr.begin(),itr.end());
     insert(root,itr);
     }
     
     int ans=0;
     for(auto itr : s2)
     {
         string s=itr;
         reverse(begin(s),end(s));
         if(search(root,itr,0) || search(root,s,0))ans++;
     }
     return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
