class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector <int> v2;
         stack <int> st;
        for(int i=nums.size()-1;i>=0;i--){
         st.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                v2.push_back(-1);
                st.push(nums[i]);
            }
            else if(nums[i]<st.top()){
                v2.push_back(st.top());
                st.push(nums[i]);
            }
            else{
                while(!st.empty() and nums[i]>=st.top()){
                    st.pop();
                }
                if(st.empty()){
                    v2.push_back(-1);
                }
                else{
                    v2.push_back(st.top());
                }
                st.push(nums[i]);
            }
        }
        reverse(v2.begin(),v2.end());
        return v2;
    }
};