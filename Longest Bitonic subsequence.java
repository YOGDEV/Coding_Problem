//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

//code

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine().trim();
            String[] s1 = s.split(" ");
            int[] nums = new int[n];
            for(int i = 0; i < s1.length; i++)
                nums[i] = Integer.parseInt(s1[i]);
            Solution ob = new Solution();
            int ans = ob.LongestBitonicSequence(nums);
            System.out.println(ans);           
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{   
    public int LongestBitonicSequence(int[] nums)
    {
        int n=nums.length;
        
        int x[]=new int[n];//lis
        int y[]=new int[n];//lds
        
        x=f(nums);
        
        nums=reverse(nums);
        y=f(nums);
        y=reverse(y);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=Math.max(ans,x[i]+y[i]-1);
        }
        return ans;
    }
    int[] f(int[] nums)
    {
        int n=nums.length;
        
        int lis[]=new int[n];
        lis[0]=1;
        
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i]=Math.max(lis[i],lis[j]+1);
                }
            }
        }
        return lis;
    }
    
    int[] reverse(int nums[])
    {
        int n=nums.length;
        for(int i=0;i<n/2;i++)
        {
            int t=nums[i];
            nums[i]=nums[n-1-i];
            nums[n-i-1]=t;
        }
        return nums;
    }
    
}
