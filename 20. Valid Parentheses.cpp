//https://leetcode.com/problems/valid-parentheses/

//code

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<s.length();i++)
        {
            if(!st.empty() and ((st.top()=='(' and s[i]==')') || (st.top()=='{' and s[i]=='}') || (st.top()=='[' and s[i]==']')  ))
               {
                   st.pop();
                   continue;
               }
                st.push(s[i]);
               
        }
        if(st.empty())return true;
        return false;
    }
};
