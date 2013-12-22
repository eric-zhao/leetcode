/*We need a "current" pointer and a stack. The stack is used to store the internal node which is
not printed yet. There is a character of the in-order traverse, which is, the top of the stack
is always followed by the "current" pointer. */

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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        vector<int> myvector;
        TreeNode *current = root;
        while(!mystack.empty() || current){
            if(current){
                mystack.push(current);
                current = current->left;
            } 
            else{
                TreeNode *node = mystack.top();
                myvector.push_back(node->val);
                mystack.pop();
                current = node->right;
            }
        }
        return myvector;
    }
};
