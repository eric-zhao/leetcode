/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).*/
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        int flag = 0;
        vector<int> level;
        stack<TreeNode*> mystack;
        queue<TreeNode*> myqueue;
        if(root==NULL) return result;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty()){
            TreeNode* node = myqueue.front();
            myqueue.pop();
            if(node != NULL){
                level.push_back(node->val);
                if(flag%2==0){
                    if(node->left!=NULL) mystack.push(node->left);
                    if(node->right!=NULL) mystack.push(node->right);
                }
                if(flag%2==1){
                    if(node->right!=NULL) mystack.push(node->right);
                    if(node->left!=NULL) mystack.push(node->left);
                }
            }
            else{
                while(!mystack.empty()){
                    TreeNode* node = mystack.top();
                    mystack.pop();
                    myqueue.push(node);
                }
                result.push_back(level);
                level.clear();
                flag++;
                if(!myqueue.empty())  myqueue.push(NULL);
            }
        }
        return result;
    }
};