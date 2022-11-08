//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//code..
//  1

//java code..................................................................
class Solution
{
    public void shortest_distance(int[][] mat)
    {
     int n=mat.length;
     for(int k=0;k<n;k++)
     {
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(mat[i][k]==-1||mat[k][j]==-1)continue;
                 if(mat[i][j]==-1||mat[i][k]+mat[k][j]<mat[i][j]){
                     mat[i][j]=mat[i][k]+mat[k][j];
                 }
                 //mat[i][j]=Math.min(mat[i][j],mat[i][k]+mat[k][j]);
             }
         }
     }
    }
}




//code
//  2
//c++ code..................................................................
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n=matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	        }
	    }
	    
	    for(int k=0;k<n;k++)
	    {
	         for(int i=0;i<n;i++)
	          {
	               for(int j=0;j<n;j++)
	               {
	                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	               }
	          }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            matrix[i][j]=-1;
	        }
	    }
	}
};
