//https://leetcode.com/problems/subarray-sum-equals-k/

//code

 int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> m;
        m.insert({0,1});
        int sum=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            auto it=m.find(sum-k);
            if(it!=m.end())
            {
                count+=it->second;
            }
            
            it=m.find(sum);
            if(it!=m.end())
            {
                it->second++;
            }
            
            m.insert({sum,1});
        }
        return count++;
    }
