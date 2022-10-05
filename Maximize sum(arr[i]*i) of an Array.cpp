/*

Given an array A of N integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n 1.
You are allowed to rearrange the elements of the array.
Note: Since output could be large, hence module 109+7 and then print answer.

*/

//code

class Solution{
    public:
    int Maximize(int a[],int n)
    {   int mod=1000000007;
        sort(a,a+n);
        long   sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=((long)a[i]*i)%mod;
        }
        return sum%mod;
    }
};
