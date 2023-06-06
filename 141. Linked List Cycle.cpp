//https://leetcode.com/problems/linked-list-cycle/

//code

//1st solution
 bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        
        while(head)
        {
            if(s.find(head)!=s.end())
                return true;
            else
            {
                s.insert(head);
                head=head->next;
            }
        }
        return false;
    }

//2nd solution
 bool hasCycle(ListNode *head) {
       ListNode* slow=head,*fast=head;
        
       while(fast and fast->next)
       {
           slow=slow->next;
           fast=fast->next->next;
           
           if(slow==fast)return true;
       }
       return false;
    }

//3rd solution
 bool hasCycle(ListNode *head) {
       ListNode* slow=head,*fast=head;
        
       while(fast and fast->next)
       {
           slow=slow->next;
           fast=fast->next->next;
           
           if(slow==fast)return true;
       }
       return false;
    }
