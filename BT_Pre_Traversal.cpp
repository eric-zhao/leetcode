/*Pre-order traverse the binary tree, recursively */


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
        vector<int> myvector;
        vector<int> left_vector;
        vector<int> right_vector;
        if (root != NULL){
            myvector.push_back(root->val);
            left_vector = preorderTraversal(root->left);
            right_vector = preorderTraversal(root->right);
            myvector.insert(myvector.end(), left_vector.begin(), left_vector.end());
            myvector.insert(myvector.end(), right_vector.begin(), right_vector.end());
            // for (std::vector<int>::iterator it = left_vector.begin() ; it != left_vector.end(); ++it)
            //     myvector.push_back(*it);
            // for (std::vector<int>::iterator it = right_vector.begin() ; it != right_vector.end(); ++it)
            //     myvector.push_back(*it);
        }
        return myvector;
    
    }
};
