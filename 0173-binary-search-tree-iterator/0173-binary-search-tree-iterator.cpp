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
class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        if(root){
            TreeNode* node=root;
            while(node){
                s.push(node);
                node=node->left;
            }
        }    
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        if(node->right){
            TreeNode* curr=node->right;
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
        } 
        return node->val;     
    }
    
    bool hasNext() {
        return !s.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */