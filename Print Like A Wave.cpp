/*
Wave Print: https://bit.ly/329Le3K
*/
#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{   vector<int> v;
    for(int j=0;j<mCols;j++)
    {
        if((j & 1)==0)//j%2==0
        {
        for(int i=0;i<nRows;i++)
            v.push_back(arr[i][j]);
        }
        else
        {
         for(int i=nRows-1;i>=0;i--)
            v.push_back(arr[i][j]); 
        }
    }
    return v;
}
