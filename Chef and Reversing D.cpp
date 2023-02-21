//https://www.codechef.com/problems/REVERSE?tab=statement

//code

#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int bfs(vector<pair<int,int>> v[],int n,vector<int> &lev)
{
    lev[1]=0;
    queue<int> q;
    q.push(1);
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        
        for(int i=0;i<v[curr].size();i++)
        {
            int child=v[curr][i].first;
            int wt=v[curr][i].second;
            
            if(lev[curr]+wt < lev[child])
            {
                lev[child]=lev[curr]+wt;
                q.push(child);
            }
        }
    }
    return lev[n-1]==INT_MAX ? -1 : lev[n-1];
}
int main() {
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> v[n+1];
    vector<int> lev(n+1,INT_MAX);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)continue;
        
        v[x].push_back({y,0});
        v[y].push_back({x,1});
    }
    
    cout<<bfs(v,n+1,lev)<<endl;
	return 0;
}
