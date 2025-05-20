class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count=1;
        int curr=arr[0];
        int qtr=arr.size()/4;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==curr)count++;
            else count=1;

            if(count>qtr)return arr[i];

            curr=arr[i];
        }
        return curr;
    }
};