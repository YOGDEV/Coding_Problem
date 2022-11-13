//https://www.codingninjas.com/codestudio/problems/rotate-matrix_981260?topList=striver-sde-sheet-problems&leftPanelTab=0

//code

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int l=0,r=m-1,t=0,b=n-1;
    
    while(l<r&&t<b )
    {
        int t1=mat[l][t];
        for(int i=t;i<b;i++)
        {
            mat[i][l]=mat[i+1][l];
        }
        
      //  int t2=mat[l][b];
        for(int i=l;i<r;i++)
        {
            mat[b][i]=mat[b][i+1];
        }
        
        //int t3=mat[r][b];
        for(int i=b;i>t;i--)
        {
            mat[i][r]=mat[i-1][r];
        }
        
       // int t4=mat[t][r];
        for(int i=r;i>l;i--)
        {
            mat[t][i]=mat[t][i-1];
        }
        mat[t][l+1]=t1;
        l++;
        r--;
        t++;
        b--;
    }

}
