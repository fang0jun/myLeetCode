/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//ʵ��һ��dfs������ڵ�ĸ߶Ȳ�

class Solution {
public:
//��ȷ�������ܣ���ĳ�ڵ�Ϊ�������ĸ߶�
//ȷ��βͷ�� β�ͣ����ڵ�Ϊ��ʱ���߶�Ϊ0�� ͷ�����߶� =1+(���ߵ���/�������ĸ߶�)
    int height(TreeNode* root){
        if(root==NULL){ return 0;}
        else{
            return max(height(root->left), height(root->right)) + 1;
        }
    }

 // ��ȷ�������ܣ��жϴ���ڵ��������Ƿ�Ϊƽ��
 // ȷ��βͷ��β����root == NULL ʱ�� ͷ������ƽ�⣬��������������ƽ��
    bool isBalanced(TreeNode* root) {
            if(root == NULL) return true;
            else{
                return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->right) && isBalanced(root->left);
            }

        } 
   
};
