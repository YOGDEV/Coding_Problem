//https://practice.geeksforgeeks.org/problems/shreyansh-and-his-bits1420/1

//code


       class Solution{
    long arr[][];
    long count(long n)
    {   arr=new long[40][40];
        for(int i=0;i<40;i++)
        Arrays.fill(arr[i],-1);
        
        int one=0,bor=0;
        long ans=0;
        while(n>0)
        {
          if((n&1)!=0)
          {
              one++;
              ans+=ncr(bor,one);
          }
          n/=2;
          bor++;
        }
        return ans;
    }
    long ncr(int n,int r)
    {
        if(r>n)return 0;
        if(r==0||r==n)return 1;
        
        if(arr[n][r]!=-1)return arr[n][r];
        
        return arr[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
    }
       }


//cpp code tle

   long long count(long long n) {

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(set_bit(i)==set_bit(n))ans++;
        }
        return ans;
    }
    long long set_bit(long n)
    {
        int c=0;
        while(n>0)
        {
            if((n&1)==1)c++;
            n/=2;
        }
        return c;
    } // Code Here
