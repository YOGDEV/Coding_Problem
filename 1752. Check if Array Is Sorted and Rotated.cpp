/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

//code
//brute force approch
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i:nums)ans.push_back(i);
        sort(ans.begin(),ans.end());
        int p;
        int t;
        int m=n;
        while(m!=0)
        {
            if(ans==nums)return true;
            else
            {   p=ans[0];
                for(int i=0;i<n;i++)
                { 
                    t=ans[(i+1)%n];
                    ans[(i+1)%n]=p;
                    p=t;
                }
                
            }
            m--;
        }
        return false;
    }
};


//optimised approch
class Solution {
    public boolean check(int[] nums) {
        int counter=0;
        
        int n=nums.length;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])//this also check nums[0]<nums[n-1]...
                counter++;
        }
        if(counter>1)return false;
        return true;
    }
}
