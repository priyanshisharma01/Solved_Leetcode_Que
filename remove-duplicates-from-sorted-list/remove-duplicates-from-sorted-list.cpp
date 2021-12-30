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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        ListNode* ptr;
        ListNode* del;

        temp = head;
        if(temp && temp->next !=nullptr) {
           ptr=temp->next;
        }
        else{
            return head;
        }
        while(ptr){
            if(temp->val==ptr->val){
            
                temp->next=ptr->next; 
            ptr=ptr->next;
                
                
            }
            else{
                ptr=ptr->next;
                temp=temp->next;
            }
        }
        return head;
    }
};