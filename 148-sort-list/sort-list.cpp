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
ListNode* findmiddle(ListNode* head){
    ListNode* fast=head->next;
    ListNode* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
            }
            return slow;
}
ListNode* merge(ListNode* head1,ListNode* head2){
    if(head1==nullptr)return head2;
    if(head2==NULL)return head1;
    ListNode* newhead;
    if(head1->val<head2->val){
        newhead=head1;
        newhead->next= merge(head1->next,head2);
    }
    else{
         newhead=head2;
       newhead->next= merge(head1,head2->next);
    }
    return newhead;
}
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
    return head;
        ListNode* middle= findmiddle(head);
         ListNode* second=middle->next;
         middle->next=NULL;

       ListNode* left = sortList(head);
        ListNode* right = sortList(second); 
        return merge(left, right);
    }
};