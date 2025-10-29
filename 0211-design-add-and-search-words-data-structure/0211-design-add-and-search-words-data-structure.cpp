struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }   
        node->setEnd();  
    }
    
    bool dfs(int idx,string &word,Node* node){
        if(idx>=word.length())return node->isEnd();
        if(word[idx]=='.'){
            for(int i=0;i<26;i++){
                Node* link=node->links[i];
                if(link){
                    if(dfs(idx+1,word,link))return true;
                }
            }
            return false;
        }
        // else{

        // }

        if(!node->containsKey(word[idx]))return false;
        node=node->get(word[idx]);
        if(dfs(idx+1,word,node))return true;

        return false;
    }

    bool search(string word) {
        Node* node=root;
        return dfs(0,word,node);            
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */