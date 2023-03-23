//https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1

//code

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int res;
    void solve(Node * root,int prev,int sum)
    {
        if(!root)return;
        
        if(root->left==nullptr and root->right==nullptr){
            res=max(res,sum-prev-root->data);
            return ;
        }
        solve(root->left,prev+root->data,sum);
        solve(root->right,prev+root->data,sum);
    }
    int maxDifferenceBST(Node *root,int target){
        res=INT_MIN;
        int sum=0;
        Node* curr=root;
        while(curr!=nullptr)
        {
           if(curr->data==target)
           break;
           else if(curr->data<target)
           {
               sum+=curr->data;
               curr=curr->right;
           }
           else
           {
               sum+=curr->data;
               curr=curr->left;
           }
        }
        if(curr==nullptr)
        return -1;
        else
        {
            if(curr->left==nullptr and curr->right==nullptr)return sum;
            
            if(curr->left)
            {
                solve(curr->left,0,sum);
            }
            if(curr->right)
            {
                solve(curr->right,0,sum);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
