229. Majority Element II

//https://leetcode.com/problems/majority-element-ii/

//code

vector<int> majorityElement(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0,j,x=nums.size()/3;
       
        for(j=1;j<nums.size();j++)
        {
            if(nums[j]!=nums[j-1])
            {
                if(j-i>x)
                    ans.push_back(nums[i]);
                
                i=j;
            }
        }
        if(j-i>x)ans.push_back(nums[i]);
        return ans;
    }
