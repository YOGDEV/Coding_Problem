//https://leetcode.com/problems/subarray-product-less-than-k/

//code

  public int numSubarrayProductLessThanK(int[] nums, int k) {
        int count=0;
        int product=1;
        
        int start=0,end=0;
        
        while(end<nums.length)
        {
            product*=nums[end];
            
            while(start <nums.length && product>=k)
            {
                product/=nums[start];
                start++;
            }
            
            if(product<k)
                count+=end-start+1;
            
            end++;
        }
        return count;
    }
