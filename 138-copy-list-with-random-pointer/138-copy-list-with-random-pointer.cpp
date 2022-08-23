class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* currTemp=head;
        //Inserting new node in between.
        while(currTemp!=NULL){
            Node* temp=new Node(currTemp->val);
            temp->next=currTemp->next;
            currTemp->next=temp;
            currTemp=currTemp->next->next;
        }
        currTemp=head;
        //Setting random pointer of new node
        while(currTemp!=NULL){
            if(currTemp->random!=NULL){
            currTemp->next->random=(currTemp->random!=NULL)?currTemp->random->next:NULL;
            }
            currTemp=currTemp->next->next;
        }
        //Seprate both the list
        currTemp=head;
        Node* copy=new Node(0);
        Node* copyTemp=copy;
        
        while(currTemp!=NULL){
            cout<<copyTemp->val<<" ";
            copyTemp->next=currTemp->next;
            //Restore orginal list
            currTemp->next=currTemp->next->next;
            
            currTemp=currTemp->next;
            copyTemp=copyTemp->next;
        }
          return copy->next;
    }
};