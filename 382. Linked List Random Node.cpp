//https://leetcode.com/problems/linked-list-random-node/

//code

ListNode * root;
    int len=0;
    Solution(ListNode* head) {
        this->root=head;
        while(head){
            len++;
            head=head->next;
        }
    }
    
    int getRandom() {
        
        int rand_ind=rand()%len;
        ListNode* temp=root;
        for(int i=0;i<rand_ind;i++)
            temp=temp->next;
        
        return temp->val;
    }
