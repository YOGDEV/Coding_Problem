/*

https://practice.geeksforgeeks.org/problems/reverse-bits3556/1

Given a 32 bit number X, reverse its binary form and print the answer in decimal.

Example 1:

Input:
X = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.
*/

 long long reversedBits(long long x) {
    
   
    //logic understanding solution
    // int i=0;
    // long long int ans=0;
    // while(x!=0)
    // {
    //     ans+=(x%2)*pow(2,31-(i++));
    //     x/=2;
    // }
    // return ans;
   
   
   //bits operation solution
    long long ans=0;
    for(int i=0;i<32;i++)
    {
        ans=ans<<1;
        if(x&1==1)
        ans=ans+1;
        
        x=x>>1;
    }
    return ans;
    }
