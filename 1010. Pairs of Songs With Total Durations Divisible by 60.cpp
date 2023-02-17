//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

//code

int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<long long > ans(60+1,0);
        
        for(auto it : time)
        {
            ans[it%60]++;
        }
        for(auto i:ans)cout<<i<<" ";
        
        ans[60]=((ans[0])*(ans[0]-1))/2;
        ans[60]+=((ans[30])*(ans[30]-1))/2;
        for(int i=1;i<30;i++)
        { 
            if(ans[i])
            {
               ans[60]+=ans[i]*ans[60-i];
            }
        }
        return ans[60];
    }
