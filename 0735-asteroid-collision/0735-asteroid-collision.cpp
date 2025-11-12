class Solution {
public:
    void help(stack<int> &s){
        if(s.size()<2)return;
        int y=s.top();
        s.pop();
        int x=s.top();
        s.pop();
        if((x>0 && y>0) || (x<0 && y<0) || (x<0 && y>0)){
            s.push(x);
            s.push(y);
            return;
        }

        if(abs(x)>abs(y)){
            s.push(x);
            help(s);
        }
        else if(abs(x)<abs(y)){
            s.push(y);
            help(s);
        }
        else{
            return;
        }

    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty() || asteroids[i]>0 || (asteroids[i]<0 && s.top()<0))s.push(asteroids[i]);
            else if(asteroids[i]<0){
                s.push(asteroids[i]);
                help(s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;    
    }
};