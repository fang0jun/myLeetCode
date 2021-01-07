/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& res, string str){
        if(root != NULL){
            str += to_string(root->val);
            if(root->right == NULL && root->left == NULL){
                res.push_back(str);
            }
            else{
                str += "->";
                dfs(root->left, res, str);
                dfs(root->right, res, str);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root,res, "");
        return res;
    }
};
