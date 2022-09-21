/*

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

*/


//solution 

//both iterative and recursive
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
class Solution {
public:
    bool palindrome(ListNode*&head,ListNode* end)//recursive
    {   
        if(end==nullptr)return true;
        bool ans=palindrome(head,end->next)&(head->val==end->val);
        head=head->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        // vector<int> v;            //iterative 
        // while(head!=nullptr)
        // {
        //     v.push_back(head->val);
        //     head=head->next;
        // }
        // int n=v.size();
        // for(int i=0;i<n/2;i++)
        // {
        //   if(v[i]!=v[n-i-1])return false;
        // }
        // return true;
        ListNode* end=head;
        return palindrome(head,end);
    }
};

