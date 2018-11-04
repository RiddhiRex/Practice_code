/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<limits.h>
bool traverse(struct TreeNode* curr, int min, int max){
    if(curr==NULL)
        return true;
    printf("%d, %d %d \n", min, max, curr->val);
    if (curr->val<min || curr->val>max) return false;
    
    return (traverse(curr->left, min, curr->val-1) && traverse(curr->right, curr->val+1, max));    
}
bool isValidBST(struct TreeNode* root) {
    if(root==NULL)
        return true;
    return traverse(root, INT_MIN, INT_MAX);
}
