// https://leetcode.com/problems/next-greater-element-i/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // find next greater element for nums2 
        // and create ans for nums1 based on that
        // ok great
        int n = nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int>ans;
        int n1 = nums1.size();
        for(int i=0;i<n1;i++){
            // auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            // cout<<*it<<" ";
            // int idx = it-nums2.begin();
            // cout<<idx<<endl;
            if(mp[nums1[i]]==0 && nums1[i]!=0 || n==1) ans.push_back(-1);
            else ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
