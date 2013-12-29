/*Output the minimum depth of the tree. Note its difference with the maximum depth of the tree.
For example, if a binary tree has only two nodes, root and its left child, then the minimum depth is 2, not 1*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right!=NULL) {
            int minRight = minDepth(root->right);
            return  minRight+1;
        }
        if(root->left!=NULL && root->right==NULL) {
            int minLeft = minDepth(root->left);
            return  minLeft+1;
        }
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left!=NULL && root->right!=NULL){
            int minLeft = minDepth(root->left);
                int minRight = minDepth(root->right);
                return minLeft <= minRight ? minLeft+1 : minRight+1;
        }
    }
};