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
    void serializeHelp(string& ans,TreeNode* root){
        if(!root){
            ans+='n';
            ans+='s';
            return;
        }
        ans+=to_string(root->val);
        ans+='s';
        serializeHelp(ans,root->left);
        serializeHelp(ans,root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        serializeHelp(ans,root);
        return ans;
    }

    TreeNode* deserializeHelp(int &i,string data){
        string temp="";
        while(data[i]!='s'){
            temp+=data[i];
            i++;
        }
        i++;
        if(temp=="n")return NULL;
        TreeNode* node=new TreeNode(stoi(temp));
        node->left=deserializeHelp(i,data);
        node->right=deserializeHelp(i,data);
        return  node;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int i=0;
        root=deserializeHelp(i,data);
        return root;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));