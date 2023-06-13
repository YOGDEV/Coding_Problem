//https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

//code

 long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int badi=-1,mini=-1,maxi=-1;
        long long ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mink or nums[i]>maxk)badi=i;
            if(nums[i]==mink)mini=i;
            if(nums[i]==maxk)maxi=i;
            ans+=max(0,min(mini,maxi)-badi);
        }
        return ans;
    }
