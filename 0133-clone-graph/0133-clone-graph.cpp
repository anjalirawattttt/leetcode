/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    

    Node* help(Node* node,unordered_map<Node*,Node*>& m){
        if(!node)return NULL;

        if(m.find(node)!=m.end())return m[node];

        Node* temp=new Node(node->val);
        m[node]=temp;

        for(Node* n:node->neighbors){
            temp->neighbors.push_back(help(n,m));
        }

        return m[node];
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> m;
        return help(node,m);
        
        
            
    }
};