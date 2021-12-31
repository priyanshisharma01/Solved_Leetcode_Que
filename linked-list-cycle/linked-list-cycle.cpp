/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(head==NULL || head->next==NULL) return false;
         unordered_set<ListNode*> h;
         while(head!=NULL)
             {
                 if(h.count(head)>0)
                   {
                      return true;
                   }
                 h.insert(head);
                 head = head->next;
             }
          return false;
}
};