//https://leetcode.com/problems/binary-tree-inorder-traversal/

//code

 public List<Integer> inorderTraversal(TreeNode root) {
        //morris traversal
        List<Integer> inorder=new ArrayList<>();
        TreeNode curr=root;
        
        while(curr!=null)//TC:(O(n))
        {
            if(curr.left==null)
            {
                inorder.add(curr.val);
                curr=curr.right;
            }
            else
            {
                TreeNode prev=curr.left;
                while(prev.right!=null && prev.right!=curr)
                {
                    prev=prev.right;
                }
                if(prev.right==null)
                {
                    prev.right=curr;
                    curr=curr.left;
                }
                else
                {
                    prev.right=null;
                    inorder.add(curr.val);
                    curr=curr.right;
                }
            }
        }
        return inorder;
    }
