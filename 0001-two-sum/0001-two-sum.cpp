class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n=nums.size();
        vector<pair<int,int>> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i].first=nums[i];
            arr[i].second=i;
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r= n-1;
        while(l<=r){
            if(arr[l].first + arr[r].first==target){
                res.push_back(arr[l].second);
                res.push_back(arr[r].second);
                break;
            }
            else if(arr[l].first+arr[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
        return res;
        
           
    }
};