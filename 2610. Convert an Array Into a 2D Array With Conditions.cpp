//https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

//code

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        
        set<int> st;
        vector<int> vis(nums.size(),0);
        
        for(int j=0;j<nums.size();j++)
        {
            if(!vis[j])
            {   
                
                for(int i=0;i<nums.size();i++)
                {
                  auto pos=st.find(nums[i]);
                  if(vis[i]==0 and pos==st.end())//elemet not  present in the set..
                  {
                   st.insert(nums[i]);
                   vis[i]=1;
                  }
                }
                
                vector<int> temp;
                set<int>::iterator itr;
                
                for(itr=st.begin();itr!=st.end();itr++)
                {
                    temp.push_back(*itr);
                    
                }
               
                    
                
                st.clear();
                 
                
                ans.push_back(temp);
                
            }
        }
        
                
        return ans;
    }
};
