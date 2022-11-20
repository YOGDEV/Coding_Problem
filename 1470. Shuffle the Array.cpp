//https://leetcode.com/problems/shuffle-the-array/

//code

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans;  //SC=O(n)
//         int i=0,j=n;
        
//         while(i<n && j<nums.size())
//         {
//             ans.push_back(nums[i++]);
//             ans.push_back(nums[j++]);
//         }
//         while(i<n)
//         {
//              ans.push_back(nums[i++]);
//         }
//         while(j<nums.size())
//         {
//             ans.push_back(nums[j++]);
//         }
//         return ans;
        int i=1;//optimised one " Inplace Solution" Sc=O(1)
        
        int j=n;
        
        while(i<nums.size() && j<nums.size()-1)
        {   int k=i;
            while(i<j)
            {
                swap(nums[i++],nums[j]);
            }
            j++;
            i=k+2;
        }
        return nums;
    }
};
