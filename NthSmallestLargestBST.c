//Nth smallest value in BST and Nth largest value in BST

#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node * insert(struct node * node, int val){
   
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

void NthLargest(struct node * root, int n){
    static int cnt=0;
    if(root==NULL)
        return;
    NthLargest(root->right, n);
    cnt++;
    if(cnt==n)
        printf("%d largest is %d  \n", n, root->val);
        
    NthLargest(root->left, n);
    return;
}
void NthSmallest(struct node * root, int n){
    static int cnt=0;
    if(root==NULL)
        return;
    NthSmallest(root->left, n);
    cnt++;
    if(cnt==n)
        printf("%d smallest is %d  \n", n, root->val);
        
    NthSmallest(root->right, n);
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
    NthLargest(root, 2);
    NthSmallest(root, 2);  
}
