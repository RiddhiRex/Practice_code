/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next=NULL;
    struct ListNode* l3=&dummy;

    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            l3->next=l1;
            l1=l1->next;
        }
        else {
            l3->next=l2;
            l2=l2->next;
        }
        l3=l3->next;
    }
    if(l1!=NULL) {
        l3->next=l1;
    }
    else if(l2!=NULL) {
        l3->next=l2;
    }
    return dummy.next;
}
