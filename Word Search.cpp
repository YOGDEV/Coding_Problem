//https://practice.geeksforgeeks.org/problems/word-search/1

//code

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int ans=0;
    void dfs(int i,int j,int ind,vector<vector<char>>& board,vector<vector<int>>& vis,string word)
    {
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or vis[i][j])return;
        if(ind==word.length())
        {
            ans=1;
            return ;
        }
        
        vis[i][j]=1;
    
        if(board[i][j]==word[ind])
        {
            dfs(i-1,j,ind+1,board,vis,word);
            dfs(i+1,j,ind+1,board,vis,word);
            dfs(i,j+1,ind+1,board,vis,word);
            dfs(i,j-1,ind+1,board,vis,word);
        }
        vis[i][j]=0;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
       int n=board.size();
       int m=board[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(!vis[i][j] and word[0]==board[i][j])
               {
                   dfs(i,j,0,board,vis,word);
                   if(ans)return true;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
