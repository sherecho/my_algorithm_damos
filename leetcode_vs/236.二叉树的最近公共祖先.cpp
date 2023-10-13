/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct info{
     bool findp;
     bool findq;
     bool iscommen;
     TreeNode * commonnode;
 };
class Solution {
public:
    info* subtask(TreeNode* root, TreeNode* p, TreeNode* q){
        info* ret=new info();
        if(root==nullptr){
            ret->findp=false;
            ret->findq=false;
            ret->iscommen=false;
            ret->commonnode=nullptr;
            return ret;

        }
        info* left=subtask(root->left, p, q);
        info* right=subtask(root->right, p, q);
        if(left->iscommen||right->iscommen){
            ret->findp=true;
            ret->findq=true;
            ret->commonnode=left->iscommen?left->commonnode:right->commonnode;
            ret->iscommen=true;
        }
        else if((left->findp&&right->findq)||(left->findq&&right->findp)){
            ret->findp=true;
            ret->findq=true;
            ret->iscommen=true;
            ret->commonnode=root;
        }
        else if((root==q&&left->findp)||(root==q&&right->findp)||(root==p&&left->findq)||(root==p&&right->findq)){
            ret->findp=true;
            ret->findq=true;
            ret->iscommen=true;
            ret->commonnode=root;
        }
        else{

            ret->findp=(left->findp||right->findp||root==p);
            ret->findq=left->findq||right->findq||root==q;
            ret->commonnode=nullptr;
            ret->iscommen=false;
        }
        return ret;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
          return nullptr;
     info* ret=subtask(root,p, q)   ;
     return ret->commonnode;
    }
};
// @lc code=end

