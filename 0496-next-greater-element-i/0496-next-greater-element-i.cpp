class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++){
            int x=nums1[i];
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    for(int k=j+1;k<n2;k++){
                        if(nums2[k]>nums2[j]){
                            x=nums2[k];
                            break;
                        }
                    }
                    nums1[i]= nums1[i]==x?-1:x;
                    break;
                }
            }
        }
        return nums1;
    }
};