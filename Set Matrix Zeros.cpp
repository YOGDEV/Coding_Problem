//https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//code

#include <bits/stdc++.h> 
#include <bits/stdc++.h>
//brute force approch  ....
void f(int i,int j,vector<vector<int>> &arr,int n,int m)
{   
    for(int k=0;k<m;k++)
    {   if(arr[i][k]==0)continue;
        arr[i][k]=-1;
    }
    for(int k=0;k<n;k++)
    { if(arr[k][j]==0)continue;
        arr[k][j]=-1;
    }
}
void fi(vector<vector<int>> &matrix,int n,int m)
{   
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j]=0;
            }
    }
}
void setZeros(vector<vector<int>> &matrix)
{       
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    f(i,j,matrix,n,m);
            }
        }
     fi(matrix,n,m);
}


//optimised approch
//considering first col and first row as the dumy arrays..

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
    int m=matrix[0].size();
    
    int col=1;
    
    for(int i=0;i<n;i++)
    {   if(matrix[i][0]==0)col=0;
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j]==0){matrix[i][0]=0;matrix[0][j]=0;}
        }
    }
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=1;j--)
        {
            if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
        }
        if(col==0)
            matrix[i][0]=col;
    }
}
