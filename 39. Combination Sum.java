/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []*/

//solution
class Solution {
    private void findCombination(int ind,int[] arr,int target,List<List<Integer>> ans,List<Integer> ds){
        if(ind==arr.length){
            if(target==0)
                ans.add(new ArrayList<>(ds));
            return ;
        }
        
        if(arr[ind]<=target)
        {
            ds.add(arr[ind]);
            findCombination(ind,arr,target-arr[ind],ans,ds);
            ds.remove(ds.size()-1);
        }
        findCombination(ind+1,arr,target,ans,ds);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        findCombination(0,candidates,target,ans,new ArrayList<>());
        return ans;
    }
}
//brute force in c++
/*
class Solution {
public:
    int search(vector<int>&c,int a)
    {
       int l1=c.size();
       int l=0,h=l1-1;
       int f=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(c[mid]==a)f=1;
            else if(c[mid]>a)h=mid-1;
            else l=mid+1;
        }
        return f;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans;
        int i;
        int l=c.size();
        sort(c.begin(),c.end());
        //searching if a single number is itself equivalent to target
        if(search(c,target)){
            vector<int> v;
            v.push_back(c[i]);
            ans.push_back(v);
        }
            
        //now checking for other combinations 
         for(i=0;i<l;i++)
         {
             while(target!=0)
             {
               if(target%c[i]==0)
               {   
                   vector<int> v;
                   for(int j=0;j<target/c[i];j++) v.push_back(c[i]);
                   ans.push_back(v);
                   break;
               }
                 else
                 {
                     int rem=target%c[i];
                     if(search(c,rem))
                     {
                        vector<int> v;
                        for(int j=0;j<target/c[i];j++) v.push_back(c[i]);
                        v.push_back(rem);
                        ans.push_back(v);
                        break;
                     }
                     
                 }
             }
         }
        
        return ans;
    }
};
*/
