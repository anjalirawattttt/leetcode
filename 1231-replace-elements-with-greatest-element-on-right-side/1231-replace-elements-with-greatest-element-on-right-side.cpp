class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int r=n-1,maxx=-1;

        while(r>=0){
            ans[r]=maxx;
            maxx=max(maxx,arr[r]);
            r--;
        }
        return ans;

    }
};