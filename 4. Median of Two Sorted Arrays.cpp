//https://leetcode.com/problems/median-of-two-sorted-arrays/

//code

public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    //using binary search...
        
        int n=nums1.length;
        
        int m=nums2.length;
        
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        
        int low=0;
        int heigh=nums1.length;
        
        int mid1=low+(heigh-low)/2;
        while(low<=heigh)
        { 
            int mid2=(n+m+1)/2-mid1;//one based indexing question ...if size of array si given allready the tine complexity will be O(log(n))...
            
            int l1=(mid1==0)?Integer.MIN_VALUE:nums1[mid1-1];
            int l2=(mid2==0)?Integer.MIN_VALUE:nums2[mid2-1];
            int r1=(mid1==n)?Integer.MAX_VALUE:nums1[mid1];
            int r2=(mid2==m)?Integer.MAX_VALUE:nums2[mid2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2!=0)return Math.max(l1,l2);
                else return (Math.max(l1,l2)+Math.min(r1,r2))/2.0;
            }
            else if(l1>r2)
            {
                heigh=mid1-1;
            }
            else
            {
                low=mid1+1;
            }
             mid1=low+(heigh-low)/2;
        }
        return 0.0;
    }
