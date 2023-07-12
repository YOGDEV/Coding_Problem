242. Valid Anagram
//https://leetcode.com/problems/valid-anagram/

//code

bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i=0,j=0;
        int n=s.size();
        while(i<n and j<n)
        {
            if(s[i++]!=t[j++])return false;
        }
        return true;
    }
