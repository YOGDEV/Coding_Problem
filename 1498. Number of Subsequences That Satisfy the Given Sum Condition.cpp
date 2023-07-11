1498. Number of Subsequences That Satisfy the Given Sum Condition
//https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

//code

ll helper(ll a,ll x,ll mod)
    {
        // ll ans=1;
        // while(x)
        // {
        //     if(x%2==1)
        //     {
        //         ans=(ans*a)%mod;
        //         x--;
        //     }else
        //     {
        //         a=(a*a)%mod;
        //         x/=2;
        //     }
        // }
        // return ans;
        if(x==0)return 1;
        ll ans=1;
        ll temp=helper(a,x/2,mod);
        if(x%2==1)
        {
            ans=(temp*temp*a)%mod;
        }
        else
        {
            ans=(temp*temp)%mod;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        vector<int> power={1};
        for(auto i=1;i<=nums.size();i++)
            power.push_back((power.back()<<1)%mod);
        
        
        sort(nums.begin(),nums.end());
        
        int res=0;
        for(int i=0,j=nums.size()-1;i<=j;i++)
        {
            while(i<=j and nums[i]+nums[j]>target)j--;
            
            if(j>=i)
            {
                //res=(res+helper(2,j-i,mod))%mod;
                res=(res+power[j-i])%mod;
            }
        }
        return res;
    }
