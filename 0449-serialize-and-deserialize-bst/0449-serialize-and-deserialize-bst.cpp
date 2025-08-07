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
    void sHelp(string& data,TreeNode* root){
        if(!root){
            data+="null,";
            return;
        }
        string s=to_string(root->val);
        data+=s+',';
        sHelp(data,root->left);
        sHelp(data,root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        sHelp(data,root);
        return data;    
    }
    TreeNode* dHelp(vector<string> &nodeVals,int &i){
        if(nodeVals[i]=="null"){
            i++;
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(nodeVals[i++]));
        node->left=dHelp(nodeVals,i);
        node->right=dHelp(nodeVals,i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodeVals;
        string temp="";   
        for(char ch:data){
            if(ch==','){
                nodeVals.push_back(temp);
                temp.clear();
            }
            else{
                temp+=ch;
            }
        }
        int i=0;
        return dHelp(nodeVals,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;