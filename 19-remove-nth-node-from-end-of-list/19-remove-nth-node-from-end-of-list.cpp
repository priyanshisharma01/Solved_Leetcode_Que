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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = new ListNode(0,head), *fast = new ListNode(0,head);
        
        while(n--)
            fast = fast->next;
        
        if(!fast->next)
            head = head->next;
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        // cout<<fast->val<<" "<<slow->val;
        slow->next = slow->next->next;
        return head;
    }
};