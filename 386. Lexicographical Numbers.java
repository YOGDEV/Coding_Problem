/*

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104
*/

//code java
class Solution {
    public void dfs(int cur, int n, List<Integer> res){
        if(cur>n)
            return;
        else{
            res.add(cur);
            for(int i=0;i<10;++i){
                dfs(10*cur+i, n, res);
            }
        }
    }
    public List<Integer> lexicalOrder(int n) {
        
        List<Integer> res = new ArrayList<>();
        for(int i=1;i<10;++i){
          dfs(i, n, res); 
        }
        return res;
    }
    
    
}

//c++ codeclass Solution {
public:
   
    vector<int> lexicalOrder(int n) {
       if(n==0) return {};
        vector<int> result;
        int current=1; //Initial element
        for(int i=0;i<n;i++){
            result.push_back(current); //Push current to the result.
            current*=10; // Add zero at the end of current.
           // cout<<current <<" ";
            while(current>n){ //If current exceeds n.
                current/=10; //Fall back to last element.
                //cout<<current <<" ";
                current++; //Get Next in order.
                //cout<<current <<" "<<endl;
                while(current%10==0)current/=10; //Remove extra trailing zeros.
                
            }
        }
        return result;
    }
};
    
