//https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

/*
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Example 1:

Input:
N = 2
arr = {2,1}
Output: {1}
Explaination: 1 is the only leaf node.

Example 2:

Input:
N = 3
Arr = {3, 2, 4}
Output: {2, 4}
Explaination: 2, 4 are the leaf nodes.

Your Task:
You don't need to read input or print anything. Your task is to complete the function leafNodes() which takes the array arr[] and its size N as input parameters and returns the leaf nodes of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 103
*/

//code

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        vector<int> ans;
        stack<int> st;
        
        st.push(arr[0]);
        for(int i=1;i<N;i++)
        {
            if(arr[i]<st.top())
            {
                st.push(arr[i]);
            }
            else
            {
                int temp=st.top();
                int removed=0;
                while(!st.empty() && st.top()<arr[i])
                {
                    st.pop();
                    removed++;
                }
                st.push(arr[i]);
                if(removed>=2)
                {
                    ans.push_back(temp);
                }
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
