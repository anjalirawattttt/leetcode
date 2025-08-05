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
    void help(vector<string> &ans,string &temp,TreeNode* root){
        if(!root)return;
        int pl=temp.length();

        string s=to_string(root->val);
        temp+=s;
        if(!root->left && !root->right){
            ans.push_back(temp);
            temp.erase(pl);
            return;
        }
        else{
            temp+="->";
        }
        help(ans,temp,root->left);
        help(ans,temp,root->right);
        temp.erase(pl);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        help(ans,temp,root);
        return ans;    
    }
};