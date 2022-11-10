//https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1

/*
Given a positive number X. Find the largest Jumping Number which is smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single-digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796, 677 and 89098 are not.

 

Example 1:

Input:
X = 10
Output:
10
Explanation:
10 is the largest Jumping Number
possible for X = 10.
Example 2:

Input:
X = 50
Output:
45
Explanation:
45 is the largest Jumping Number
possible for X = 50.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function jumpingNums() which takes an Integer X as input and returns the largest Jumping Number less than or equal to X.

 

Expected Time Complexity: O(k), where k is no of jumping numbers
Expected Auxiliary Space: O(k), where k is no of jumping numbers

 

Constraints:
1 <= X <= 109
*/

//code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        
        queue<long long >q;
        for(long long i=1;i<=9;i++)
        {
            q.push(i);
        }
        
        long long ans=0;
        
        while(!q.empty())
        {
            long long num=q.front();
            q.pop();
            
            if(num>X)continue;
            
            ans=max(ans,num);
            
            int lastdigit=num%10;
            if(lastdigit!=0)
            {
                long long first=num*10+(lastdigit-1);
                q.push(first);
            }
            if(lastdigit!=9)
            {
                long long second=num*10+(lastdigit+1);
                q.push(second);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
