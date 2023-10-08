// Definition for a Node.
/*class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    TreeNode* subencod( vector<Node*> children){
        TreeNode * head=nullptr;
        TreeNode *cur=nullptr;
        for(auto child=children.begin();child!=children.end();child++){
            if(head==nullptr){
            head=new TreeNode((*child)->val);
            head->left=subencod((*child)->children);
            cur=head;
            }
            else{
                cur->right=new TreeNode((*child)->val);
                cur=cur->right;
                cur->left=subencod(( *child)->children);   
                
            }
        }
        return head;
    }
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(root==nullptr)
          return nullptr;
    TreeNode * returnhead=new TreeNode(root->val);
    returnhead->left=subencod(root->children); 
    return returnhead;  
    }
	
    // Decodes your binary tree to an n-ary tree.
    vector<Node*>de(TreeNode * rootleft){
    vector<Node*>ret;
    TreeNode * cur=rootleft;
    while(cur!=nullptr){
        vector<Node*>childs=de(cur->left);
         Node * tmp=new Node(cur->val,childs);
         ret.push_back(tmp);
         cur=cur->right;
    }
    return ret;
    }
    Node* decode(TreeNode* root) {
        if(root==nullptr)
        return nullptr;
        vector<Node*> children=de(root->left);
       Node * head=new Node(root->val,children) ;
       return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));