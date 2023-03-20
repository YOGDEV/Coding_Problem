//https://leetcode.com/problems/can-place-flowers/

//code

bool canPlaceFlowers(vector<int>& arr, int n) {
        for(int i=0;i<arr.size() and n;i++)
        {
            if(arr[i]==0)
            {
                int next=(i==arr.size()-1) ?0 : arr[i+1];
                int prev=(i==0)?0 :arr[i-1];
                
                if(next==0 and prev==0)
                {
                    n--;
                    arr[i]=1;
                }
            }
        }
        return n==0;
    }
