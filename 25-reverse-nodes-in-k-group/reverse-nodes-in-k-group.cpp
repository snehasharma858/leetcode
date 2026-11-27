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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head == NULL || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
       
        ListNode* prev=dummy;
        ListNode* curr=head;
       
        while(curr!=NULL){
             ListNode* val=curr;
             int count = 0;
           
            while(val != NULL && count < k) {
                val = val->next;
                count++;
            }
            if(count < k) {
                break;
            }
            ListNode* curr1 = curr;
            ListNode* prev1 = NULL;

            for(int i = 0; i < k; i++) {
                ListNode* temp = curr1->next;

                curr1->next = prev1;

                prev1 = curr1;
                curr1 = temp;
            }
            prev->next = prev1;
            curr->next=curr1;
            prev=curr;
            curr=curr1;


            }
        

        return dummy->next;
    }
};