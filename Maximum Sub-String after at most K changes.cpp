//https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes3220/1

/*

We have a string s of length n, which contains only UPPERCASE characters and we have a number k (always less than n). We can make at most k changes in our string. In one change, you can replace any s[i] (0<= i < n) with any uppercase character (from 'A' to 'Z'). After k changes, find the maximum possible length of the sub-string which have all same characters.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Change 2 'B' into 'A'. 
Now s = "AAAA"

Example:

Input: s = "ADBD", k = 1
Output: 3
Explanation: Change 'B' into 'D'.
Now s = "ADDD"

Your Task:
You don't need to read or print anything. Your task is to complete the function characterReplacement() which takes s and k as input parameters and returns the maximum length of sub-string after doing k changes.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(26)
 

Constraints:
1 <= n <= 105
0 <= k < n
*/

//code

//c++ code TC(n) and SC(26)
//{ Driver Code Starts

class Solution {
	public:
		int characterReplacement(string s, int k){
		    
		    int freq[26]={0};
		    int n=s.length();
		    int st=0;
		    int max_freq=0;
		    int ans=0;
		    
		    for(int e=0;e<n;e++)
		    {   
		        max_freq=max(max_freq,++freq[s[e]-'A']);
		        
		        while(e-st+1 -max_freq>k)
		        {
		            //reduce the  window size
		            freq[s[st]-'A']--;
		            st++;
		        }
		        ans=max(ans,e-st+1);
		    }
		    return ans;
		}

};


//java code TC(n) and SC(26)
class Solution
{
    public int characterReplacement(String s, int k)
    {
    //code goes here    
        int n = s.length();
        char ch[] = s.toCharArray();
        
        int freq[] = new int[26];
        int st=0; int max_freq=0; int ans=0;
        
        for(int e=0; e<n; e++)
        {
            max_freq = Math.max(max_freq, ++freq[ch[e]-'A']);
            while(e-st+1 - max_freq >k)
            {
                // reduce the window size from st, st++;
                freq[ch[st]-'A']--;
                st++;
            }
            // process the ans 
            ans = Math.max(ans, e-st+1);
        }
        return ans;
    }
}


//tle solution
TC(n^2)
class Solution {
	public:
		int characterReplacement(string s, int k){
		    
		    
		    int n=s.length();
		    int max_freq=0;
		    int ans=k;
        
		    
		    for(int i=0;i<n-k;i++)
		    {   int freq[26];
		     for(int j=i;j<n;j++)
         {
           max_freq=max(max_freq,++freq[s[j]-'A']);
           int ss_len=j-i+1;
           if(ss_len-max_freq<=k)
           ans=max(ans,ss_len);
         }
      }    
		    return ans;
		}

};
