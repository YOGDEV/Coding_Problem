//https://leetcode.com/problems/maximum-gap/

//code

 int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(auto i:nums)
        {
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        int d=ceil(((maxi-mini)*1.0)/(n-1));
        if(d<1)d=1;
        cout<<d;
        vector<pair<int,int>> bucket(n,{INT_MAX,INT_MIN});
        for(int i=0;i<n;i++)
        {
            int ind=(nums[i]-mini)/d;
            bucket[ind].first=min(bucket[ind].first,nums[i]);
            bucket[ind].second=max(bucket[ind].second,nums[i]);
        }
        int ans=0,preMax=bucket[0].second;
        for(int i=1;i<n;i++)
        {
            if(bucket[i].first==INT_MAX)continue;
            ans=max(ans,bucket[i].first-preMax);
            preMax=bucket[i].second;
        }
        
        return ans;
    }
