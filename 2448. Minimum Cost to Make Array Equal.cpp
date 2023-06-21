//https://leetcode.com/problems/minimum-cost-to-make-array-equal/

//code

long long f(vector<int>& nums,vector<int>& cost,long long x)
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(nums[i]-x)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=f(nums,cost,1),l=1,r=1000000,x;
        while(l<r)
        {
          x=(l+r)/2;
          long long y1=f(nums,cost,x) ,y2=f(nums,cost,x+1);
          ans=min(y1,y2);
          if(y1<y2)
              r=x;
          else
              l=x+1;
        }
        return ans;
  }


//second approach

 long long f(vector<int>& nums,vector<int>& cost,long long x)
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(nums[i]-x)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans,total=0;
        vector<pair<int,int>> v(nums.size());
        
        for(int i=0;i<nums.size();i++)
            v[i]={nums[i],cost[i]};
        sort(v.begin(),v.end());
        
        long long sum=0;
        for(int i=0;i<v.size();i++)sum+=v[i].second;
        
        int i=0;
        while(total<(sum+1)/2 and i<nums.size())
        {
            total+=v[i].second;
            ans=v[i].first;
            i++;
        }
        
        return f(nums,cost,ans);
  }
