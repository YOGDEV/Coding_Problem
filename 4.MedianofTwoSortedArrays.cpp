/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

//code.......................................................................
 class Solution {
public:
    void merge(vector<int>& num1,int n,vector<int>& num2,int m,int num3[])
    {
        int i=0,j=0,k=0;
        while(i<n&& j<m)
        {
            if(num1[i]<=num2[j])
                num3[k++]=num1[i++];
            else
                num3[k++]=num2[j++];
        }
        while(i<n)
        {
            num3[k++]=num1[i++];
        }
        while(j<m)
        {
            num3[k++]=num2[j++];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //size of both arrays
        int n=nums1.size();
        int m=nums2.size();
        //third array
        int nums3[n+m];
        //merge function
        merge(nums1,n,nums2,m,nums3);
        //sort
        
        sort(nums3,nums3+(n+m));
        double ans;
        if((n+m)%2==0)
        {
            int l=((n+m)/2)-1;
            ans=(nums3[l]+nums3[l+1])/2.0;
        }
        else
        {
            ans=nums3[(n+m)/2];
        }
        return ans;
    }
   
};
