class Solution {
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        stack<int> s;
        vector<int> left(n,1);
        vector<int> right(n,1);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i])s.pop();
            left[i]=s.empty() ? i+1 :i-s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            right[i]=s.empty() ? n-i : s.top()-i;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            ans=(ans+(1LL*arr[i]*left[i]*right[i])%MOD)%MOD;
        }
        return (int)ans;    
    }
};