//https://leetcode.com/problems/product-of-array-except-self/

//code

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size(),1);
        vector<int> prefix(nums.size(),1);
        
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i]=prefix[i-1]*nums[i];
        
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
            suffix[i]=suffix[i+1]*nums[i];
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                nums[i]=suffix[i+1];
                continue;
            }
            if(i==nums.size()-1)
            {
                nums[i]=prefix[i-1];
                continue;
            }
            if(i+1<nums.size() and i-1>=0)
            nums[i]=suffix[i+1]*prefix[i-1];
        }
        return nums;
    }
