//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

//code

class Solution
{

	
	    public int minDifference(int arr[], int n) 
	{ 
	    // Your code goes here
	    Map<String,Integer> map=new HashMap<>();
	    return dfs(arr,n-1,0,0,map);
	} 
	public int dfs(int[]arr,int n,int s1,int s2,Map<String,Integer> map){
	    if(n<0){
	        return Math.abs(s1-s2);
	    }
	    String key=n+","+s1;
	    if(!map.containsKey(key)){
	        int first=dfs(arr,n-1,s1+arr[n],s2,map);
	        int sec=dfs(arr,n-1,s1,s2+arr[n],map);
	        map.put(key,Math.min(first,sec));
	    }
	    return map.get(key);
	}// Your code goes here
	
}



//my code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int f(int ind,int arr[],int n,int s1,int s2,int sum,vector<vector<int>>& store)
    {   //int temp=0,k;
        if(ind==n )
        {
            //temp=0;
            //for(auto i:diff)temp+=i;
            
            //k=sum-temp;
            //if(k> temp)return sum;
            //return temp-k;
            return abs(s1-s2);
        }
    //      for(auto i:diff)temp+=i;
          if(store[ind][s1]!=-1)return store[ind][s1];
        
        //diff.push_back(arr[ind]);
        int take= f(ind+1,arr,n,s1+arr[ind],s2-arr[ind],sum,store);
        //diff.pop_back();
        
        int nontake=f(ind+1,arr,n,s1,s2,sum,store);
        
        return store[ind][s1]=min(take,nontake);
    }
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    
	    
	    for(int i=0;i<n;i++)sum+=arr[i];
	    vector<vector<int>> store( n , vector<int> (sum, -1)); 
	    vector<int> diff;
	    
	    return f(0,arr,n,0,sum,sum,store);
	    
	} 

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
