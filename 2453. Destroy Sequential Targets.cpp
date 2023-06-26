//https://leetcode.com/problems/destroy-sequential-targets/

//code

int destroyTargets(vector<int>& nums, int space) {
        map<int,int> m;
        int mx=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]%space]++;
            mx=max(mx,m[nums[i]%space]);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]%space]==mx)
                ans=min(ans,nums[i]);
        }
        return ans;
    }
