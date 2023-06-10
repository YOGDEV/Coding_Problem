//https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1

//code

 void merge(int arr[],int start,int end ,int mid)
        {
            int i=start,j=mid+1;
            
            while(i<=mid and arr[i]<0)i++;
            while(j<=end and arr[j]<0)j++;
            int k=i,l=j-1;
            int temp=mid;
            
            while(i<temp)swap(arr[i++],arr[temp--]);
            temp=mid+1;
            j=j-1;
            while(temp<j)swap(arr[temp++],arr[j--]);
            
            while(k<l)swap(arr[k++],arr[l--]);
            
        }
        void helper(int arr[],int start , int end)
        {
            if(start< end)
            {
                int mid=(start+end)/2;
                helper(arr,start,mid);
                helper(arr,mid+1,end);
                merge(arr,start,end,mid);
            }
        }
        void Rearrange(int arr[], int n)
        {
            helper(arr,0,n-1);
        }
