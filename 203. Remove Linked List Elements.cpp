/*

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
*/

//code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {//recursive
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        
        ListNode *newElement=removeElements(head->next,val);
        
        if(head->val==val)
            return newElement;
        else
        {
            head->next=newElement;
            return head;
        }
       // return head;
    }
};




//java code //iterative

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head==null)return head;
        
    while(head!=null && head.val==val)head=head.next;
        
        ListNode current=head;
        
        while(current!=null && current.next!=null)
        {
            if(current.next.val==val)
            {
                current.next=current.next.next;
            }
            else
                current=current.next;
        }
        return head;
    }
}
