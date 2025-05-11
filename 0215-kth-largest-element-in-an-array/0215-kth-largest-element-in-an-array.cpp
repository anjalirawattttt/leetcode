class Solution {
public:
    int partition(vector<int> &nums,int low,int high,int k){
        int pivot=nums[high];
        int i=low;

        for(int j=low;j<high;j++){
            if(nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[high]);
        return i;
    }

    int quickSelect(vector<int> &nums,int low,int high,int k){
        if(low<=high){
            int pivotIndex=partition(nums,low,high,k);
            if(pivotIndex==k)return nums[pivotIndex];
            else if(pivotIndex<k) return quickSelect(nums,pivotIndex+1,high,k);
            else return quickSelect(nums,low,pivotIndex-1,k);
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k-1);  
    }
};