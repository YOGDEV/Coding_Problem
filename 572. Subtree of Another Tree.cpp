//https://leetcode.com/problems/subtree-of-another-tree/

//code

 bool ans;
    bool match(TreeNode* root, TreeNode* subRoot)
    {
        if(root!=nullptr and subRoot!=nullptr)
        {
            int a=match(root->left,subRoot->left);
            int b=match(root->right,subRoot->right);
            
            if(root->val==subRoot->val and a and b)
                return true;
            else
                return false;
        }
        else if(root==nullptr and subRoot==nullptr)return true;
        else return false;
    }
    void helper(TreeNode* root, TreeNode* subRoot)
    {
        if(root!=nullptr)
        {
            helper(root->left,subRoot);
            
            bool x=match(root,subRoot);
            if(x)ans=x;
            
            helper(root->right,subRoot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        helper(root,subRoot);
        return ans;
    }
};


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
