//https://practice.geeksforgeeks.org/problems/akku-and-binary-numbers0902/1

//code

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        Solution ob = new Solution();
        ob.precompute();
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            long L = Long.parseLong(input_line[0]);
            long R = Long.parseLong(input_line[1]);
            long ans = ob.solve(L, R);
            System.out.println(ans);
        }
    }
}


// } Driver Code Ends


//User function Template for Java


class Solution{
    ArrayList<Long> arr=new ArrayList<>();
    void precompute(){
        for(int i=0;i<63;i++)
        {
            for(int j=i+1;j<63;j++)
            {
                for(int k=j+1;k<63;k++)
                {
                    arr.add((long)Math.pow(2,i)+(long)Math.pow(2,j)+(long)Math.pow(2,k));
                }
            }
        }
        Collections.sort(arr);
    }
    long solve(long L, long R){
       long ans;
       //find L
       int index1=Collections.binarySearch(arr,L);
       index1=(index1<0)? -index1-1 : index1;
       
       //find R
       int index2=Collections.binarySearch(arr,R);
       index2=(index2<0)? -index2-2 : index2;
       
       return index2-index1+1;
    }
    
}
