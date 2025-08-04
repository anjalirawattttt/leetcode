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
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        //c->r,multiset of values
        map<int,map<int,multiset<int>>> m;
        //node,{r,c}
        queue< pair< TreeNode* ,pair<int,int> > > q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto[node,p]=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            m[c][r].insert(node->val);
            if(node->left)q.push({node->left,{r+1,c-1}});
            if(node->right)q.push({node->right,{r+1,c+1}});
        }

        for( auto &[col,rowMap] : m){
            vector<int> colValues;
            for( auto &[row,nodeVals] : rowMap){
                colValues.insert(colValues.end(),nodeVals.begin(),nodeVals.end());   
            }
            ans.push_back(colValues);
        }




        return ans;   
    }
};