/**

 \* Definition for a binary tree node.

 \* struct TreeNode {

 \*   int val;

 \*   TreeNode *left;

 \*   TreeNode *right;

 \*   TreeNode() : val(0), left(nullptr), right(nullptr) {}

 \*   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

 \*   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 \* };

 */



 // 前序遍历收集树叶，然后判断即可

class Solution {

public:

  void dfs(TreeNode* root,vector<int>& vec){

?    if (root == NULL) return;

?    if(root->left == NULL && root->right == NULL){

?      vec.push_back(root->val);

?    }

?    dfs(root->right,vec);

?    dfs(root->left,vec);  

  }





  bool leafSimilar(TreeNode* root1, TreeNode* root2) {

?    vector<int> temp1, temp2;

?    dfs(root1,temp1); dfs(root2,temp2);

?    return temp1 == temp2;

  }

};
