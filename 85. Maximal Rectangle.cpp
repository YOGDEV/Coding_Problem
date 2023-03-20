//https://leetcode.com/problems/maximal-rectangle/

//code

class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        stack<int> st;
        int n=heights.size();
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() and (i==n || heights[st.top()]>=heights[i]))
            {
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else width=i-st.top()-1;
                    
                ans=max(ans,width*height);
            }
            
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        
        vector<int> height(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            int area=largestRectangleArea(height);
            ans=max(ans,area);
        }
        return ans;
    }
};
