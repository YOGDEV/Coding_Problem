//https://leetcode.com/problems/middle-of-the-linked-list/


//c++ code class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr)return 0;
        ListNode* ptr=head;
        int res=0;
        vector<int> v;
        
        while(ptr->next!=nullptr){
        v.push_back(ptr->val);
        ptr=ptr->next;
        }
        
        v.push_back(ptr->val);
        int n=v.size();
        if(n%2!=0)
        {
             int l=(n+1)/2;
            for(int i=1;i<l;i++)head=head->next;
        }
        else
        {
            int l=(n/2)+1;
            for(int i=1;i<l;i++)head=head->next;
        }
        return head;
        
        
    }
};


//java code

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode temp=head;
        int c=0;
        while(head!=null)
        {
            c++;
            head=head.next;
        }
        
        
         for(int i=0;i<c/2;i++)
             temp=temp.next;
        // if(c%2!=0)return temp;
            
        return temp;
        
    }
}
