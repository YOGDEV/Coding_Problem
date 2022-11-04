//link:  https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


//code
//TC=O(n) and SC=O(1)


//code


#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    
    for(int i=0;i<n;i++)
    {
        int take=nums[i];
        if(i>1)take+=prev2;
        
        int nontake=0+prev;
        
        int curi=max(take,nontake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
