class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,int> m;
        for(int i=0;i<n2;i++){
            for(int j=i+1;j<n2;j++){
                if(nums2[j]>nums2[i]){
                    m[nums2[i]]=nums2[j];
                    break;
                }
            }
            m[nums2[i]]= m[nums2[i]]==0?-1:m[nums2[i]];
        }

        for(int i=0;i<n1;i++){
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};