//https://leetcode.com/problems/reverse-words-in-a-string/

//code

class Solution {
public:
    string reverseWords(string s) {
        
        int i=0,j=0;
        string ans;
        
        for(i=0;i<s.length();i++)//removing the front spaces
            if(s[i]!=' ')break;
        s=s.substr(i);
        
        for(i=s.length()-1;i>=0;i--)//removing the back spaces 
            if(s[i]!=' ')break;
        s=s.erase(i+1);
        
        i=0;
        while(j<s.length())
        {
            if(j-1>=0 and s[j]==' ' and s[j-1]==' '){i=j+1;j++;continue;}//removing the mid spaces
            if(s[j]==' ')
            {
                ans=(" "+s.substr(i,j-i))+ans;
                i=j+1;
            }
            j++;
        }
        ans=s.substr(i,j-i+1)+ans;
        
        
        return ans;
    }
};
