/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
      if(root==nullptr)
          return true;
      TreeNode *cur;
      queue<TreeNode*> myqueue;
      myqueue.push(root);
      bool leaf=false;//标记是否为叶子结点
      while(!myqueue.empty()){
           cur=myqueue.front();
           myqueue.pop();
           if(cur->left!=nullptr)
             myqueue.push(cur->left);
           if(cur->right!=nullptr)
             myqueue.push(cur->right);           
           
           if(cur->left==nullptr&&cur->right!=nullptr)
             return false;
           if(leaf&&(!(cur->left==nullptr&&cur->right==nullptr)))
             return false;
           if(!(cur->right!=nullptr&&cur->left!=nullptr))
              leaf=true;
          
        
      }
      return true;

    }
};
// @lc code=end

