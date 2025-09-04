class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        //maxheap - element , index
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k-1;i++){
            pq.push({nums[i],i});
        }
        int l=0,r=k-1;
        while(r<n){
            pq.push({nums[r],r});
            while(pq.top().second<l ){
                pq.pop();
            }
            int ele=pq.top().first;
            int idx=pq.top().second;
            ans.push_back(ele);
            l++;
            r++;
        }
        return ans;
    }
};