class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n=nums.size();
    int l=0, mid=0, r=n-1;
    while(mid<=r){
        if(nums[mid]==0){
            swap(nums[l],nums[mid]);
            l++;
            mid++;
        }
        else if(nums[mid]==1){
            swap(nums[mid],nums[l]);
            mid++;
        }
        else{
            swap(nums[r],nums[mid]);
            r--;
        }
    }    
}

};