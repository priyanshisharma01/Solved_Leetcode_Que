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
    ListNode* removeElements(ListNode* head, int val) {
     
        if(!head)return head;
        
        while(head && head->val == val)
        {
            ListNode * tdel = head;
            head = head->next;
            delete tdel;
        }
        ListNode * curr = head;
        ListNode * prev = nullptr;
        while(curr)
        {
            if(curr->val == val)
            {
                ListNode * tdel = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete tdel;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};