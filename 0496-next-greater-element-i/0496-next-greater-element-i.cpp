class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        unordered_map<int,int> m;

        stack<int> s;
        s.push(-1);
        for(int i=n2-1;i>=0 ;i--){
            if(nums2[i]>s.top()){
                while(s.top()!=-1 && nums2[i]>s.top()){
                    s.pop();
                }
                m[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
            else{
                m[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
        }

        for(int i=0;i<n1;i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};