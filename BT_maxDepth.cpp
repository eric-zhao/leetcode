/*Output the maximum depth of a binary tree*/
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
    int maxDepth(TreeNode *root) {
        int max;
        if(root == NULL) return 0;
        else{
            int maxLeft = maxDepth(root->left);
            int maxRight = maxDepth(root->right);
            return  maxLeft>maxRight  ? maxLeft+1 : maxRight+1;
        }
    }
};