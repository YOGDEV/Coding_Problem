//https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1

//code

//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            //br.readLine();
            String s;
            s = br.readLine();
            
            Solution obj = new Solution();
            int res = obj.beautySum(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int beautySum(String s) {
        
        int n=s.length();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int freq[]=new int[26];
            for(int j=i;j<n;j++)
            {
                freq[s.charAt(j)-'a']++;
                int mini=getmin(freq);
                int maxi=getmax(freq);
                ans+=maxi-mini;
            }
        }
        return ans;
    }
    static int getmin(int arr[])
    {
        int min=Integer.MAX_VALUE;
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)min=Math.min(min,arr[i]);
        }
        return min;
    }
    static int getmax(int arr[])
    {
        int max=Integer.MIN_VALUE;
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)max=Math.max(max,arr[i]);
        }
        return max;
    }
}
        
