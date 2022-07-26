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
    int length(ListNode* head)
    {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            
            c++;
            temp=temp->next;
        }
        return c;
    }
    ListNode* middleNode(ListNode* head) {
        int size=length(head);
        int mid=size/2;
        int count=0;
        ListNode* headmid;
        ListNode* temp=head;
        while(count!=mid)
        {
            temp=temp->next;
            count++;
            
        }
        if(mid%2==0)
        {
            headmid=temp;
            return headmid;
        }
        else
        {
            headmid=temp;
            return headmid;

        }
        return headmid;
        
    }
};