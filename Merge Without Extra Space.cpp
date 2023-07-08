//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

//code
//4 Approches

//first
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long arr[n+m];
            for(int i=0;i<n;i++)arr[i]=arr1[i];
            
            for(int j=0;j<m;j++)arr[n+j]=arr2[j];
            
            sort(arr,arr+(n+m));
            
            
            for(int i=0;i<n;i++)
            arr1[i]=arr[i];
            
            for(int i=0;i<m;i++)
            arr2[i]=arr[n+i];
        } 

//second
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long arr[n+m];
            int i=0,j=0,k=0;
            
            while(i<n and j<m)
            {
                if(arr1[i]<=arr2[j])
                arr[k++]=arr1[i++];
                else
                arr[k++]=arr2[j++];
            }
            while(i<n)
            {
                arr[k++]=arr1[i++];
            }
            while(j<m)
            {
                arr[k++]=arr2[j++];
            }
            
            for(i=0;i<n;i++)arr1[i]=arr[i];
            for(i=0;i<m;i++)arr2[i]=arr[n+i];
        } 

//third
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=n-1,j=0;
            while(i>=0 and j<m)
            {
                if(arr1[i]>arr2[j])
                swap(arr1[i--],arr2[j++]);
                else
                break;
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 

//fourth
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int l=n+m; 
            int gap=l/2 + l%2;
            
            while(gap>0)
            {
                int i=0,j=i+gap;
                while(j<l)
                {
                    if(i<n and j>=n)
                    {
                        if(arr1[i]>arr2[j-n])swap(arr1[i],arr2[j-n]);
                    }
                    else if(i>=n)
                    {
                        if(arr2[i-n]>arr2[j-n])swap(arr2[i-n],arr2[j-n]);
                    }
                    else
                    {
                        if(arr1[i]>arr1[j])
                        swap(arr1[i],arr1[j]);
                    }
                    i++;
                    j++;
                }
                if(gap==1)break;
                gap=gap/2 + gap%2;
            }
        } 
