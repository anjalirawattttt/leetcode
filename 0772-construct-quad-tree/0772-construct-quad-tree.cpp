/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* help(int a1,int a2,int b1,int b2,int c1,int c2,int d1,int d2,vector<vector<int>>& grid,int n){
        if(a1>c1 || a2>d2)return NULL;
        // a1=b1
        // c1=d1
        // a2=c2
        // b2=d2
        int val=-1;
        bool allSame=true;
        for(int i=a1;i<=d1;i++){
            for(int j=a2;j<=d2;j++){
                if(val==-1)val=grid[i][j];
                else{
                    if(val!=grid[i][j]){
                        allSame=false;
                    }
                }

                if(!allSame)break;
            }
            if(!allSame)break;
        }
        if(allSame)return new Node(val,1);

        Node* root=new Node(1,0); 
        n=n/2;
        root->topLeft = help(a1,a2 , b1,b2-n , c1-n,c2 , d1-n,d2-n ,grid,n);
        root->topRight = help(a1,a2+n , b1,b2 , c1-n,c2+n , d1-n,d2 ,grid,n); 
        root->bottomLeft = help(a1+n,a2 , b1+n,b2-n , c1,c2 , d1,d2-n ,grid,n); 
        root->bottomRight = help(a1+n,a2+n , b1+n,b2 , c1,c2+n , d1,d2 ,grid,n);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return new Node(grid[0][0],1);
        return help(0,0,0,n-1,n-1,0,n-1,n-1,grid,n); 
    }
};