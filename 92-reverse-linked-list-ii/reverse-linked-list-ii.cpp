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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
   
     ListNode* prev=NULL;
     ListNode* curr=head;
     
     int count=1;
    
     while(count<left){
       
        prev=curr;
        curr=curr->next;
        count++;
     }   
    //  //  center
     
     ListNode* prev1=NULL;
     
     ListNode* center=curr;
     while(count>=left && count<=right){
        ListNode* val=curr->next;
        curr->next=prev1;
        prev1=curr;
        curr=val;
        count++;
     }
     // right
       center->next = curr;
     
    
  
     if(prev!=NULL){
        prev->next = prev1;
     }
     else{
         head = prev1;
     }


        return head;
    }
};