//https://practice.geeksforgeeks.org/problems/c928f229cc972671d91c5e9f6b222414912cc88a/1

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> segment;
    void build_segment(int ind,int left,int right,string s)
    {
        if(left==right)
        {
           segment[ind][s[right]-'a']=1;
           return;
        }
        int mid=left+(right-left)/2;
        
        build_segment(ind*2+1,left,mid,s);
        build_segment(ind*2+2,mid+1,right,s);
        
        for(int i=0;i<26;i++)
        segment[ind][i]=segment[ind*2+1][i]+segment[ind*2+2][i];
    }
    
    void update(int ind ,int left,int right,int Unidex,char c,string s)
    {
        if(Unidex<left || right<Unidex)return;
        segment[ind][s[Unidex]-'a']--;
        segment[ind][c-'a']++;
        
        if(left==right)return ;
        int mid=left + (right-left)/2;
        update(ind*2+1,left,mid,Unidex,c,s);
        update(ind*2+2,mid+1,right,Unidex,c,s);
    }
    
    void helper(int ind,int left,int right,int start,int end ,vector<int>& temp)
    {
        if(left>end or right<start)return;
        if(left>=start and right<=end)
        {
            for(int i=0;i<26;i++)
            temp[i]+=segment[ind][i];
            return;
        }
        int mid=left+(right-left)/2;
        helper(ind*2+1,left,mid,start,end,temp);
        helper(ind*2+2,mid+1,right,start,end,temp);
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        segment=vector<vector<int>>(n*4,vector<int>(26,0));
        build_segment(0,0,n-1,s);
        vector<char> ans;
        for(int i=0;i<q;i++)
        {
            if(queries[i][0]=="1")
            {
                int Unidex=stoi(queries[i][1]);
                char c=queries[i][2][0];
                update(0,0,n-1,Unidex,c,s);
                s[Unidex]=c;
            }
            else
            {
                int start=stoi(queries[i][1]);
                int end=stoi(queries[i][2]);
                int k=stoi(queries[i][3]);
                vector<int> temp(26,0);
                helper(0,0,n-1,start,end,temp);
                int i;
                for(i=25;i>=0;i--)
                {
                    k-=temp[i];
                    if(k<=0)break;
                }
                ans.push_back('a'+i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
