//https://leetcode.com/problems/range-sum-of-bst/description/

//code

void inorder(TreeNode *root,int l,int r,int &sum)
{
   
    if(root)
    {
        inorder(root->left,l,r,sum);
        if(root->val>=l && root->val <=r)
        sum+=root->val;
        inorder(root->right,l,r,sum);
    }
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inorder(root,low,high,sum);
        return sum;
    }


//second code

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root==NULL)
            return 0;
        if(root->val<low)
            return rangeSumBST(root->right,low,high);
        if(root->val>high)
            return rangeSumBST(root->left,low,high);
        return rangeSumBST(root->left,low,high) + root->val + rangeSumBST(root->right,low,high);
    }
};
