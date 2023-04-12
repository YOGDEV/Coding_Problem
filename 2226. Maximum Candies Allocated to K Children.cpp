//https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

//code

class Solution {
public:
    int helper(vector<int>& candies, long long k,long long mid)
    {
        long long cnt=0;
        
        for(auto itr : candies)
        {
            cnt+=(itr/mid);
        }
        if(cnt>=k)return 1;
        return 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int i=1;
        int j=*max_element(candies.begin(),candies.end());
        
        int ans=0;
        
        while(i<=j)
        {
            int mid=i +(j-i)/2;
            
            if(helper(candies,k,mid))
            {
                ans=mid;
                i=mid+1;
            }
            else
                j=mid-1;
        }
        return ans;
    }
};
