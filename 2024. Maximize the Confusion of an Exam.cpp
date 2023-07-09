//https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

//code

 int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0,cnt=0,left=0;
        int n=answerKey.size();
        
        for(int i=0;i<n;i++)
        {
            if(answerKey[i]=='F')
                cnt++;
            while(cnt>k)
            {
                if(answerKey[left]=='F')
                    cnt--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        cnt=0;
        left=0;
        for(int i=0;i<n;i++)
        {
            if(answerKey[i]=='T')
                cnt++;
            while(cnt>k)
            {
                if(answerKey[left]=='T')
                    cnt--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
