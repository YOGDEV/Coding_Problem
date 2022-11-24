//https://leetcode.com/problems/word-search/

//code

 public boolean exist(char[][] board, String word) {
        char[] arr= word.toCharArray();
        int n=board.length;
        if(n==0)return false;
        
        int m=board[0].length;
        
        if(word.length()==0)return false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[0]==board[i][j])
                {
                    if(dfs(board,arr,i,j,n,m,0))return true;
                }
            }
        }
        return false;
    }
    
    boolean dfs(char[][] board,char []arr,int i,int j,int n,int m,int k)
    {
        if(k>=arr.length)return true;
        if(i<0||i>=n||j<0||j>=m||board[i][j]=='!'||board[i][j]!=arr[k])return false;
        
        board[i][j]='!';
        boolean temp=false;
        
        int []x={0,0,1,-1};
        int []y={-1,1,0,0};
       
        for(int ind=0;ind<4;ind++)
        {
            temp=temp||dfs(board,arr,i+x[ind],j+y[ind],n,m,k+1);
        }
        board[i][j]=arr[k];
        return temp;
    }
