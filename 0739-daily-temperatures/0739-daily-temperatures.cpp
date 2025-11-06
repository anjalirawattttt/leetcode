class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n=temperatures.size();
        s.push(-1);
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            nge[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            if(nge[i]==-1)nge[i]=0;
            else nge[i]=nge[i]-i;
        }
        return nge;
    }
};