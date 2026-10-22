/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* newhead=NULL;
        Node* prev = NULL;
        unordered_map<Node* ,Node*>mp;
        while(temp!=nullptr){
            Node* node=new Node(temp->val);
            mp[temp]=node;
            if(prev!=NULL){
                prev->next=node;
                prev=node;
            }
            else{
newhead=node;
prev=newhead;
            }
            temp=temp->next;
           
        }
        temp=head;
        Node* newtemp=newhead;
        while(temp!=NULL){
         if (temp->random != NULL) { newtemp->random = mp[temp->random]; }
            temp=temp->next;
            newtemp=newtemp->next;
        }
    return newhead;}
};