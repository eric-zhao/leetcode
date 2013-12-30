/*Level traverse a binary tree using iterative method*/
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> level;
        vector<vector<int>> level2;
        queue<TreeNode*> myqueue;
        stack<vector<int>> mystack;
        if(root==NULL) return result;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty()){
            TreeNode* node = myqueue.front();
            myqueue.pop();
            if(node!=NULL){
                level.push_back(node->val);
                if(node->left != NULL) myqueue.push(node->left);
                if(node->right != NULL) myqueue.push(node->right);
            }
            else{
                mystack.push(level);
                level.clear();
                if(!myqueue.empty()) myqueue.push(NULL);
            }
        }
        while(!mystack.empty()){
            result.push_back(mystack.top());
            mystack.pop();
        }
        return result;
    }
};