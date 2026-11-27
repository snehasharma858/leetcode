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
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        int c=1;
        while(curr!=NULL){
            if(c==count-n+1){
                ListNode* temp=curr->next;
                if(prev == NULL) {
                    head = curr->next;
                }
                else{
                prev->next=temp;}
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;

            }
            c++;
            
        }
        return head;
    }
};