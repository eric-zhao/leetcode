/*Binary Tree Level Order Traversal: Given a binary tree, return the bottom-up level order traversal of its nodes' values.
This is done by recursion. The problem can be divided as: (1) once level n-1 is traversed by level, then level n is just needed to 
be appended at last.*/
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
        vector<vector<int>> myVector;
        if (root == NULL) return myVector;
        else{
            vector<vector<int>> leftVector = levelOrderBottom(root->left);
            vector<vector<int>> rightVector = levelOrderBottom(root->right);
            int leftSize = leftVector.size();
            int rightSize = rightVector.size();
            vector<int> inner;
            inner.push_back(root->val);
            if(leftSize >= rightSize){
                while(rightSize){
                    rightSize--;
                    leftSize--;
                    leftVector[leftSize].insert(leftVector[leftSize].end(), rightVector[rightSize].begin(), rightVector[rightSize].end());
                }
                myVector.insert(myVector.begin(), leftVector.begin(), leftVector.end());
                myVector.push_back(inner);
            }
            else{
                while(leftSize){
                    leftSize--;
                    rightSize--;
                    rightVector[rightSize].insert(rightVector[rightSize].begin(), leftVector[leftSize].begin(), leftVector[leftSize].end());
                }
                myVector.insert(myVector.begin(), rightVector.begin(), rightVector.end());
                myVector.push_back(inner);
            }
        }
        return myVector;
    }
};