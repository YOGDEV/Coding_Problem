//https://leetcode.com/problems/minimum-time-to-complete-trips/

.//code
  
#define  ll long long int
    bool helper(ll min_time,vector<int>& time , int totalTrips)
    {
        ll total_time_taken=0;
        for(auto itr:time)
        {
            total_time_taken+=min_time/itr;
        }
        return total_time_taken>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l=1,r=(1e14);
        while(l<r)
        {
            ll mid=(l+r)/2;
            if(helper(mid,time,totalTrips))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return r;
    }
