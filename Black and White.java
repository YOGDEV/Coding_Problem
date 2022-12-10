//https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1

//code with space of(array of size 8)   TC=O(1)
static long numOfWays(int N, int M)
    {
        long mod=1000000007;
        int dir1[]={2,2,1,-1,-2,-2,-1,1};
        int dir2[]={-1,1,2,2,1,-1,-2,-2};
        
        long attack=0;
        
        long total=((N*M)%mod*((N*M)-1)%mod)%mod;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                for(int k=0;k<8;k++)
                {
                    int nx=i+dir1[k];
                    int ny=j+dir2[k];
                    
                    if(nx>=0 && nx<N && ny>=0 && ny<M)attack++;
                }
            }
        }
        return (total%mod-attack%mod)%mod;
    }



//second solution c++ code 
//TC=O(1)  and SC=O(1)

static long numOfWays(int n, int m)
    {
        long mod = 1000000007;
        long total =( (m*n)%mod *(m*n-1)%mod)%mod;
        
        if(n>=1 && m>=2)
        {
            total -=  4*(n-1)*(m-2);
        }
        if(m>=1 && n>=2)
        {
            total -=  4*(m-1)*(n-2);
            
        }
        
        return total;
    }
