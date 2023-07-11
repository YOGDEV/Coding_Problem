//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

//code

int maxScore(vector<int>& cardPoints, int k) {
        
        vector<int> sum(cardPoints.size(),0);
        int Sum=0;
        for(int i=0;i<cardPoints.size();i++)
        {
            Sum+=cardPoints[i];
            sum[i]=Sum;
        }
        if(cardPoints.size()==k)return Sum;
        int score=0,ans=0;
        for(int i=0;i<=k;i++)
        {
            int j=i+cardPoints.size()-k-1;
            if(i==0)ans=sum[j];
            else
            ans=sum[j]-sum[i-1];
            score=max(score,Sum-ans);
        }
        return score;
    }
