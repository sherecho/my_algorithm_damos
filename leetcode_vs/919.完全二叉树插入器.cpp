/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
#include<queue>
using namespace std;
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
     this->root=root;
    queue<TreeNode*>tmpQueue;
    //TreeNode *cur=root;
    tmpQueue.push(root);
    while(!tmpQueue.empty()){
        TreeNode * cur=tmpQueue.front();
        tmpQueue.pop();
        //从左到右的顺序找不满的结点
        if(cur->left!=nullptr)
            tmpQueue.push(cur->left);
        if(cur->right!=nullptr)
            tmpQueue.push(cur->right);
        //将不满的结点存储
        if(!((cur->left!=nullptr)&&(cur->right!=nullptr)))
           candidate.push(cur);
    }
    }
     
    int insert(int val) {
     TreeNode * newchild=new TreeNode(val);
     TreeNode * parent=candidate.front();
     int ret=parent->val;
     if(parent->left==nullptr)
       parent->left=newchild;
     else{
        parent->right=newchild;
        candidate.pop();
     }
       
     //candidate.pop();//错的
     candidate.push(newchild);
     return ret;
    }
    
    TreeNode* get_root() {
    return root;
    }
private :
 queue<TreeNode*> candidate;
  TreeNode * root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

