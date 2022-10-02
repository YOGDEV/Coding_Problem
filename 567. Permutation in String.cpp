/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

https://leetcode.com/problems/permutation-in-string/

*/

class Solution {
public:
    bool check(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        int count1[26]={0};
        for(int i=0;i<s1.length();i++)
        {  
            count1[s1[i]-'a']++;
        }
        
        int i=0;
        int count2[26]={0};
        int window=s1.length();
        
        while(i<window && i<s2.length())
        {
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(check(count1,count2))
        return true;
        
        while(i<s2.length())
        {
            int newchar=s2[i]-'a';
            count2[newchar]++;
            
            int index=s2[i-window]-'a';
            count2[index]--;
            
            i++;
            
            if(check(count1,count2))
                return true;
        }
        return false;
    }
};
