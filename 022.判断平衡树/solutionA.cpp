/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//实现一个dfs计算各节点的高度差

class Solution {
public:
//明确函数功能：求某节点为根的树的高度
//确定尾头： 尾巴：当节点为空时，高度为0； 头部：高度 =1+(更高的左/右子树的高度)
    int height(TreeNode* root){
        if(root==NULL){ return 0;}
        else{
            return max(height(root->left), height(root->right)) + 1;
        }
    }

 // 明确函数功能：判断传入节点代表的树是否为平衡
 // 确定尾头：尾：当root == NULL 时， 头：自身平衡，且其左右子树都平衡
    bool isBalanced(TreeNode* root) {
            if(root == NULL) return true;
            else{
                return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->right) && isBalanced(root->left);
            }

        } 
   
};
