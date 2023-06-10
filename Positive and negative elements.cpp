//https://practice.geeksforgeeks.org/problems/positive-and-negative-elements4613/1

//code

 vector<int> arranged(int a[],int n)
    {
        vector<int> ans(n,0);
        int j=0,k=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 and k<n)
            {
                ans[k]=a[i];
                k+=2;
            }
            if(a[i]>=0 and j<n)
            {
                ans[j]=a[i];
                j+=2;
            }
        }
        return ans;
