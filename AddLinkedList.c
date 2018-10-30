//Add two integers that is represented in linked list. 

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node * next;
};
struct node * insert(struct node* root, int val){
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->next=NULL;
    struct node* curr;
    if(root==NULL){
        root=newnode;
    }
    else{
        curr=root;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newnode;
    }
    return root;
}
int getNumberFromLL(struct node * head){
    int no=0;
    struct node * curr;
    curr=head;
    while(curr!=NULL){
        no=(no*10)+curr->val;
        curr=curr->next;
    }
    return no;
}
struct node* addLinkedList(struct node * head1, struct node * head2){
    struct node * head3=NULL;
    int n=0;
    int no1=getNumberFromLL(head1);
    int no2=getNumberFromLL(head2);
    int sum=no1+no2;
    while(sum>0){
        n = sum%10;
        sum=(int) sum/10;
        struct node * curr = (struct node *)malloc(sizeof(struct node));
        curr->val=n;
        curr->next=NULL;
        if(head3==NULL){
            head3=curr;
        }
        else{
            curr->next=head3;
            head3=curr;
        }
    }
    return head3;
}
void printing(struct node * root){
    struct node* curr;
    curr=root;
    while(curr!=NULL){
        printf("%d ", curr->val);
        curr=curr->next;
    }
    printf("\n");
}
void main(){
    struct node *head1, *head2, *head3;
    head1 = insert(head1, 2);
    head1 = insert(head1, 1);
    head2 = insert(head2, 3);
    head2 = insert(head2, 0);
    head3 = addLinkedList(head1, head2);
    printing(head3);
}
