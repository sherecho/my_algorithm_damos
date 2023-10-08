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
    void subjudge(bool & isbalanced,int&height ,TreeNode * root){
        if(root==nullptr){
            isbalanced=true;
            height=0;
            return;
        }    
        int heightleft,heightright;
        bool ifleftb,ifrightb;       
        subjudge(ifleftb, heightleft, root->left);
        subjudge(ifrightb, heightright, root->right);
        if((ifleftb &&ifrightb)&&(abs(heightleft-heightright)<=1))
          isbalanced=true;
        else
          isbalanced=false;
        height=heightleft>heightright?heightleft+1:heightright+1;
    }
    bool isBalanced(TreeNode* root) {
        bool isbalanced;
        int height;
         subjudge(isbalanced,height,root);
        return isbalanced;
    }
};

