//Linked list insertion, deletion, searching, reversing, printing
#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *next;
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
void printing(struct node * root){
    struct node* curr;
    curr=root;
    while(curr!=NULL){
        printf("%d ", curr->val);
        curr=curr->next;
    }
    printf("\n");
}
struct node * delete(struct node * root, int val){
    struct node* curr;
    struct node* prev;

    if(root->val==val){
        root=root->next;
        return root;
    }
    prev=root;
    curr=root->next;
    while(curr!=NULL){
        if(curr->val==val){
            prev->next=curr->next;
            free(curr);
            return root;
        }
        prev=curr;
        curr=curr->next;
    }
    return root;
}
void search(struct node * root, int val){
    struct node * curr;
    int i=0;
    curr=root;
    while(curr!=NULL) {
        if(curr->val==val){
            printf("found in index %d \n", i);
        }
        curr=curr->next;
        i+=1;
    }
}
struct node * reverse(struct node * root){
    struct node * curr, * nxt, * prev=NULL;
    curr=root;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next=prev;
        prev= curr;
        curr=nxt;
    }
    return prev;
}
void main(){
    struct node* root=NULL;
    root = insert(root, 1);
    root=insert(root, 2);
    root = insert(root, 3);
    root=insert(root, 4);
    root = insert(root, 5);
    root=insert(root, 6);
    printing(root);
    root = delete(root,1);
    root = delete(root,5);
    printing(root);
    search(root, 37);
    root = reverse(root);
    printing(root);
}
