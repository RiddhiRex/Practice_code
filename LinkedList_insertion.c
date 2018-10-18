#include <stdio.h>
#include <stdlib.h>

struct node{
  int val;
  struct node* left;
  struct node* right;
};

struct node* InsertNode(struct node* root, int v){
struct node* newNode = (struct node*)malloc(sizeof(struct node));
  
  if(newNode == NULL ){
    return newNode;
  }
  newNode->val = v;
  newNode->left = NULL;
  newNode->right = NULL;
  char* printvar;
  
  struct node * iter = root;
  struct node * parent = NULL;
  

  if(root==NULL){
    //root = newNode
    printf("Inserted node is root with val %d \n", newNode->val);
    return newNode;
  }
  else{
    while(iter){
      if(v <= iter->val){
        parent = iter;
        iter= iter->left;
      }
      else{
        parent = iter;
        iter = iter->right;
      }
    }
    
    if(v <= parent->val){
      parent->left = newNode;
      printvar = "left";
    }
    else{
      parent->right = newNode;
      printvar = "right";
    }
    
    printf("Inserted Node val is %d, parent is %d, location is %s \n", newNode->val, parent->val, printvar);
  }

  return root;
}

int main() {
 
     int input[]={20, 7, 15, 12, 45, 55, 42, 12, 13, 21,3,6,43,51,100,1};
     int len = sizeof(input)/sizeof(input[0]);
     struct node* root = NULL;

     for (int i=0; i<len; i++) {
         struct node* temp = InsertNode(root, input[i]); 
        if(temp == NULL){
            printf("Node %d insertion failed\n", input[i]);
         }
       else{
         root = temp;
       }
     }    
}
