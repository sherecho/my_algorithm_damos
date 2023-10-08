/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
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
  int max_length;
  int height;
 };
class Solution {
public:
    info * subtask(TreeNode * root){
        info * infor=new info();
        if(root==nullptr){
           infor->max_length=-1;
           infor->height=-1;
           return infor;
        }
        info* left=subtask(root->left);
        info* right=subtask(root->right);
        infor->height=left->height>right->height? left->height+1:right->height+1;
        int max1=left->max_length>right->max_length?left->max_length:right->max_length;
        int max2=left->height+1+right->height+1;
        infor->max_length=max(max1,max2);
        return infor;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       info* r= subtask(root);
       return r->max_length;
    }
};
// @lc code=end

