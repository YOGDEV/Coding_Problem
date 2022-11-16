//https://leetcode.com/problems/guess-number-higher-or-lower/

//code

 int guessNumber(int n) {
        int l=0,r=n;
        int mid=l+(r-l)/2;
        
        while(l<=r)
        {
            if(guess(mid)==0)break;
            else if(guess(mid)==1)
                l=mid+1;
            else r=mid-1;
            mid=l+(r-l)/2;
        }
        return mid;
    }
