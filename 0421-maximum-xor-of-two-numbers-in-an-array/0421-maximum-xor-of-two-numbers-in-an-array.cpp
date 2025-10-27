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
        Node* node=root;
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
        Node* node=root;
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
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        Trie* t=new Trie();
        for(int &num:nums){
            t->insert(num);
        }
        for(int &num:nums){
           ans=max(ans,t->getMax(num));
        }
        return ans;
    }
};