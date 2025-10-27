struct Node{
    Node* links[2];
    bool containsBit(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node= root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsBit(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        int ans=0;
        Node* node= root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsBit(1-bit)){
                ans=ans|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return ans;
    }
};
class Solution {
public:
    static bool myCmp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int size=nums.size();
        vector<int> ans(n);

        sort(nums.begin(),nums.end());
        vector<vector<int>> temp(queries.begin(),queries.end());
        for(int i=0;i<n;i++){
            temp[i].push_back(i);
        }  
        sort(temp.begin(),temp.end(),myCmp);  

        Trie* t=new Trie();
        int idx=0;
        for(int i=0;i<n;i++){
            while(idx<size && nums[idx]<=temp[i][1]){
                t->insert(nums[idx]);
                idx++;
            }
            if(idx==0){
                ans[temp[i][2]]=-1;
            }
            else{
                ans[temp[i][2]]=t->getMax(temp[i][0]);
            }

        }
        return ans;
    }
};