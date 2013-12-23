/*Besides stack and current node, post-order traverse also needs the "lastVisit" node. */
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> myvector;
        stack<TreeNode*> mystack;
        TreeNode *current;
        TreeNode *lastVisit = NULL;
        current = root;
        while(!mystack.empty() || current){
            if(current != NULL){
                mystack.push(current);
                current = current -> left;
            }
            else{
                TreeNode *top = mystack.top();
                if(top->right != NULL && top->right != lastVisit){
                    current = top->right;
                }
                else{
                    mystack.pop();
                    myvector.push_back(top->val);
                    lastVisit = top;
                }
            }
        }
        
        return myvector;
    }
};
