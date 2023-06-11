//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

//code

 int maxValue(int n, int index, int maxSum) {
        int right=n-index-1;
        int left=index;
        
        int h=maxSum,l=1;
        long long ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            long long  rightSum=0,leftSum=0,el=mid-1;
            
            if(right<=el)
            {
                rightSum=(el*(el+1))/2 - ((el-right)*(el-right+1))/2;
            }
            else
            {
                rightSum=(el*(el+1))/2+(right-el);
            }
            
            if(left<=el)
            {
                leftSum=(el*(el+1))/2-((el-left)*(el-left+1))/2;
            }
            else
            {
                leftSum=(el*(el+1))/2+(left-el);
            }
            
            long long sum=rightSum + leftSum + mid;
            
            if(sum<=maxSum)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
