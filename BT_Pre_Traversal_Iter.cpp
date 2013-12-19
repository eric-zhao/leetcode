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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        vector<int> myvector;
        if(root == NULL) return myvector;
        mystack.push(root);
        while(mystack.size() != 0){
            TreeNode *node = mystack.top();
            mystack.pop();
            myvector.push_back(node->val);
            if(node->right != NULL)
                mystack.push(node->right);
            if(node->left != NULL)
                mystack.push(node->left);
        }
        return myvector;
    
    }
};
