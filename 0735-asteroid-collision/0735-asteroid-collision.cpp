class Solution {
public:
    void help(stack<int> &s){
        int x=s.top();
        s.pop();
        int y=s.top();
        s.pop();
        if(x<0 && y>0){
            int x1=abs(x);
            int y1=abs(y);
            if(x1>y1){
                s.push(x);
            }
            else if (y1>x1){
                s.push(y);
            }
            if(s.size()>=2)help(s);
        }
        else{
            s.push(y);
            s.push(x);
        }
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            s.push(asteroids[i]);
            if(s.size()>=2)help(s);
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;    
    }
};