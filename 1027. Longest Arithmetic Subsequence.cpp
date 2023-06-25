//https://leetcode.com/problems/longest-arithmetic-subsequence/

//code

int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int,int> dp[nums.size()+1];
        int ans=0;
        if(nums.size()<=2)return nums.size();
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                int cnt=1;
                
                if(dp[j].count(diff))cnt=dp[j][diff];
                
                dp[i][diff]=cnt+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
