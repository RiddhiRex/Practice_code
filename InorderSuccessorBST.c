//Finding inorder successor in BST and inorder traversal

#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node * insert(struct node * node, int val) {
   if(node==NULL){
       struct node * newnode=(struct node *)malloc(sizeof(struct node));
       newnode->val=val;
       newnode->left=NULL;
       newnode->right=NULL;
       return newnode;
   }
   if(node->val>val)
        node->left=insert(node->left, val);
    else
        node->right=insert(node->right, val);
    return node;
}

int NextInorderNode(struct node * root, int val){
    struct node *curr;
    int succ=0;
    curr=root;
    while(curr!=NULL){
        if(curr->val>val){
            succ=curr->val;
            curr=curr->left;
        }
        else
            curr=curr->right;
    }
    return succ;
}
void printInorder(struct node * tnode){
    if(tnode==NULL)
        return;
    printInorder(tnode->left);
    printf("%d ", tnode->val);
    printInorder(tnode->right);
    return;
}
void main(){
    struct node * root;
    root=NULL;
    int succ;
    root=insert(root, 4);
    root=insert(root, 2);
    root=insert(root, 6);
    root=insert(root, 3);
    succ= NextInorderNode(root, 2);
    printf("%d is Successor \n ", succ);
    printInorder(root)
}
