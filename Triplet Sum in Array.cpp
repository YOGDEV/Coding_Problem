//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

//code

bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n-2;i++)
        {
            int sum=A[i];
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int curr=sum+A[j]+A[k];
                if(curr==X)return true;
                
                if(curr>X)
                k--;
                else
                j++;
            }
        }
        return false;
    }
