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
ListNode* getlast(ListNode* head){
    while(head->next!=NULL){
        head=head->next;

    }
    return head;
}
ListNode* getlastii(ListNode* head){
    while(head->next->next!=NULL){
        head=head->next;

    }
    return head;
}
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr )return nullptr;
    if(head->next==NULL)return head;
    int count=0;
     ListNode* temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    k=k%count;
        while(k>0){
            ListNode* last=getlast(head);
            ListNode* lastii=getlastii(head);
            lastii->next=nullptr;
            last->next=head;
            head=last;
            k--;
        }
  return head;  }
};