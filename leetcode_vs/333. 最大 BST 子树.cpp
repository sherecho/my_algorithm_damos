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
 struct info{
 int maxnodes;
 bool isBst;
 int min;
 int max;
 };
class Solution {
public:
    info* subtask(TreeNode * root){
        if(root==nullptr)
            return nullptr;
        info * left=subtask(root->left);
        info* right=subtask(root->right);
        info* ret=new info();
        int leftnum=left==nullptr? 0:left->maxnodes;
        int rightnum=right==nullptr? 0:right->maxnodes;
        bool leftisB=left==nullptr?true:left->isBst;
        bool rightisB=right==nullptr?true:right->isBst;
        bool leftjud=left==nullptr? true:left->max<root->val;
        bool rightjud=right==nullptr?true:right->min>root->val;
        if(leftisB&&rightisB&&leftjud&&rightjud){
          ret->isBst=true;
          ret->maxnodes=leftnum+rightnum+1;
          ret->min=left==nullptr? root->val:left->min;
          ret->max=right==nullptr?root->val:right->max;
        }
        else{
          ret->isBst=false;
          ret->maxnodes=leftnum>rightnum?leftnum:rightnum;
          ret->min=left==nullptr? root->val:left->min;
          ret->max=right==nullptr?root->val:right->max; 
        }
         
        return ret;
    }
    int largestBSTSubtree(TreeNode* root) {
      if(root==nullptr)
        return 0;
        info* ret=subtask(root);
        return ret->maxnodes;
    }
};