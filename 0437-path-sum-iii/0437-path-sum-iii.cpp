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
    int help(TreeNode* node,int &targetSum,unordered_map<long long,int> &m,long long &sum){
        if(!node)return 0;
        sum+=node->val;
        int temp=0;
        if(m.find(sum-targetSum)!=m.end()){
            temp+=m[sum-targetSum];
        }
        m[sum]++;
        int l=help(node->left,targetSum,m,sum);
        int r=help(node->right,targetSum,m,sum);
        m[sum]--;
        sum-=node->val;
        return temp+l+r;

    }
    int pathSum(TreeNode* root, int targetSum) {
        long long sum=0;
        unordered_map<long long,int> m;
        m[0]=1;
        return help(root,targetSum,m,sum);    
    }
};