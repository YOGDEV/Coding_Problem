/*
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

//code
//usng binary search in each row of the given matrix...
class Solution {
public:      
    
     int isBinary(vector<vector<int>> matrix,int i,int l,int r,int target)
         {
            int mid=l+(r-l)/2;
          
           while(l<=r)
            {
                 if(matrix[i][mid]==target)
                     return 1;
                 else if(matrix[i][mid]>target)
                     r=mid-1;
                 else
                     l=mid+1;
                 mid=l+(r-l)/2;
            }
             return 0;
         }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int  l=0,r=m-1;
        
        for(int i=0;i<n;i++)
        {
         if(target>matrix[i][r])
             continue;
          if(isBinary(matrix,i,l,r,target))
           // if(binary_search(matrix[i].begin(),matrix[i].end(),target))
             return true;
        }
        return false;
    }
};
