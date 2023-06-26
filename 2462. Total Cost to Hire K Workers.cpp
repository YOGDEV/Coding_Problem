//https://leetcode.com/problems/total-cost-to-hire-k-workers/

//code

long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> p1,p2;
        
        int i=0;
        int j=costs.size()-1;
        
        while(k--)
        {
            while(p1.size()<candidates and i<=j)p1.push(costs[i++]);
            while(p2.size()<candidates and j>=i)p2.push(costs[j--]);
            
            
            int cost1=p1.size()>0?p1.top():INT_MAX;
            int cost2=p2.size()>0?p2.top():INT_MAX;
            
            if(cost1<=cost2)
            {
                ans+=cost1;
                p1.pop();
            }
            else
            {
                ans+=cost2;
                p2.pop();
            }
        }
        return ans;
    }
