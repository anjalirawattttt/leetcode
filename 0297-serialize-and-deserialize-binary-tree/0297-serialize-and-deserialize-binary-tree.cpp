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
    
    void shelp(TreeNode* root,string &tree){
        if(!root){
            tree+="null,";
            return;
        }
        tree+=to_string(root->val) + ",";
        shelp(root->left,tree);
        shelp(root->right,tree);    
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree="";
        shelp(root,tree);
        return tree;     
    }


    TreeNode* buildTree(vector<string> &nodeVals,int& i){
        if(i>=nodeVals.size() || nodeVals[i]=="null"){
            i++;
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(nodeVals[i++]));
        node->left=buildTree(nodeVals,i);
        node->right=buildTree(nodeVals,i);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodeVals;
        string token="";

        for(char ch:data){
            if(ch==','){
                nodeVals.push_back(token);
                token.clear();
            }
            else{
                token+=ch;
            }
        }  
        //nothing after comma
        int i=0;
        return buildTree(nodeVals,i);

        

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));