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

    ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr )return nullptr;
    if(head->next==NULL)return head;
    int count=1;
     ListNode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
        count++;
    }
    k=k%count;
    temp->next=head;
       ListNode* tail=head;
      for(int i=0;i<count-k-1;i++){
        tail=tail->next;
      }
      ListNode* newHead=tail->next;
      tail->next=NULL;
      return newHead; }
};