//https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


//code

#include <bits/stdc++.h>
long long int  f(vector<int> & nums)
{
    int n=nums.size();
    long long int prev=nums[0];
    long long int  prev2=0;
    
    for(int i=1;i<n;i++)
    {
        long long int  take=nums[i];
        if(i>1)take+=prev2;
        
        long long int nontake=0+prev;
        long long int  curi=max(take,nontake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1,temp2;
    int  n=valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    
    for(int i=0;i<n;i++)
    {
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);
    }
    
    return max(f(temp1),f(temp2));
}
