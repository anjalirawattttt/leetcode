class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int r=n-1,maxx=-1;

        while(r>=0){
            int x=arr[r];
            arr[r]=maxx;
            maxx=max(maxx,x);
            r--;
        }

        return arr;

    }
};