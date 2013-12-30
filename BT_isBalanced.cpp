/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.*/
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

    int getDepth(TreeNode *root){
        int depth;
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        else{
            int left = getDepth(root->left);
            int right = getDepth(root->right);
            return left >= right ? left+1 : right+1;
        }
    }
    
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        else{
            int leftDepth = getDepth(root->left);
            int rightDepth = getDepth(root->right);
            bool leftBalance = isBalanced(root->left);
            bool rightBalance = isBalanced(root->right);
            return abs(leftDepth-rightDepth)<=1 && leftBalance && rightBalance ? true : false; //The tree is balance should fulfill 3 requirements at the same time: (1) left sub-tree is balanced (2) right sub-tree is balanced (3) the depth difference between the left and right sub-tree should no more than 1.
        }
    }
    
    
};