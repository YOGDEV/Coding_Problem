//https://leetcode.com/problems/relative-ranks/

//code

vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n=score.size();
        for(int i=0;i<n;i++)
        {
            pq.push({score[i],i});
        }
        
        vector<string> ans(n);
        if(!pq.empty())
        {
            ans[pq.top().second]="Gold Medal";
            pq.pop();
        }
        if(!pq.empty())
        {
            ans[pq.top().second]="Silver Medal";
            pq.pop();
        }
        if(!pq.empty())
        {
            ans[pq.top().second]="Bronze Medal";
            pq.pop();
        }
        int k=4;
        while(!pq.empty())
        {
            ans[pq.top().second]=to_string(k);
            k++;
            pq.pop();
        }
        return ans;
    }
