//https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching2259/1

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> ans;
    struct node{
      node* child[26]={nullptr};
      vector<string> v;
    };
    node* root;
    Solution()
    {
        root=new node();
    }
    
    void insert(string str)
    {
        node* temp=root;
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(str[i]>='A' and str[i]<='Z'){
            if(!temp->child[str[i]-'A'])temp->child[str[i]-'A']=new node();
            temp=temp->child[str[i]-'A'];
            }
        }
        temp->v.push_back(str);
    }
    void printif(node *root)
    {
        for(auto itr:root->v)ans.push_back(itr);
        for(int i=0;i<26;i++)
        {
            node* temp=root->child[i];
            if(temp)printif(temp);
        }
    }
    int search(string pattern)
    {
        node *temp=root;
        int n=pattern.length();
        for(int i=0;i<n;i++)
        {
            if(!temp->child[pattern[i]-'A'])return 0;
            temp=temp->child[pattern[i]-'A'];
        }
        printif(temp);
        return 1;
    }
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
    for(auto itr:Dictionary)insert(itr);
    
    search(Pattern);
    if(ans.size()==0)return {"-1"};
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
