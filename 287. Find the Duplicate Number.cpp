/*

https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

*/

//code

//java
class Solution {
    public int findDuplicate(int[] nums) {
       int low = 1, high = nums.length - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int i=0;i<nums.length;i++)
            {
                if(nums[i] <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low; 
    }
}



//////////////////////////////////////////////////////////////////////////////////
//c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     
        unordered_map<int,int> m;
        for(auto i:nums)
            m[i]++;
        
        int maxi=INT_MIN,ans;
        for(auto i:m){
            if(maxi<i.second){
                ans=i.first;
                maxi=i.second;
            }
        }
        
        return ans;
    }
};
