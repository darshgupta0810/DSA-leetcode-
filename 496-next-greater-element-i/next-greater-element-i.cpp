class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int p=nums1.size();
        int n=nums2.size();
        vector <int> ans;
        stack <int> st;
        for(int i=n-1;i>=0;i--){
         if(st.empty()){
                ans.push_back(-1);
                st.push(nums2[i]);
         }
         else if(nums2[i]<st.top()){
            ans.push_back(st.top());
            st.push(nums2[i]);
         }
         else{
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }  
            if(st.empty()){
                ans.push_back(-1);
            } 
            else{
                ans.push_back(st.top());
            }
            st.push(nums2[i]);
         }
        }
         reverse(ans.begin(),ans.end());
         unordered_map <int,int> mp;
         vector <int> final;
        
        for(int i=0;i<n;i++){
          mp[nums2[i]]=ans[i];
        }
        for(int x:nums1){
            final.push_back(mp[x]);
        }
        return final;
    }
};