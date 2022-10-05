/*

https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&curated[]=7&sortBy=submissions

Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, K = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= K <= 108
1 <= Arr[i] <= 106

 
 
 */

//code

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        maxi=max(arr[i],maxi);
        sort(arr,arr+n);
        
        int count[maxi+1]={0};
        
        for(int i=0;i<n;i++)
        count[arr[i]]++;
        int c=0;
        int i=0,j=n-1;
        while(i<j)
        {
           
             if(arr[i]+arr[j]==k && arr[i]==arr[j])
            { 
            int n=count[arr[i]];
              while(n!=0)
              {
                  c+=n-1;
                  n--;
              }
              break;
            }
            else  if(arr[i]+arr[j]==k )
            {
                c+=count[arr[i]]*count[arr[j]];
                count[arr[i]]=0;
                count[arr[j]]=0;
                i++;
                j--;
            }
            else if(arr[i]+arr[j]>k)
            j--;
            else
            i++;
        }
        return c;
    
       
    }
};
