//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

//code

//time limit exceded solution

 bool canPair(vector<int> nums, int k) {
        int n=nums.size();
        vector<int> v(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
            {
                for(int j=0;j<n;j++)
                {
                     if(v[j]==-1 and i!=j)
                     {
                         if((nums[i]+nums[j])%k==0)
                         {
                           v[i]=v[j]=1;  
                         }
                     }
                }
            }
        }
        for(int i=0;i<n;i++)
        if(v[i]==-1)return false;
        return true;
    }

//non tle solution

 public boolean canPair(int[] nums, int k) {
        int n=nums.length;
        //total  TC=O(n)+O(n) => O(n)...
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        
        for(int i=0;i<n;i++)//O(n)
        {
            int rem=nums[i]%k;
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        
        for(int i=0;i<n;i++)//O(n)
        {
            //2 cases
            int rem=nums[i]%k;
            if(rem==0)
            {
                if(map.get(rem)%2==1)return false;
            }
            else
            {
                if(map.get(rem)!=map.get(k-rem))return false;
            }
        }
        return true;
    }
