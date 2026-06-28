class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pref[n];
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(pref[i]==k){
            count++;
            }
        }
        int r=1;
        while(r<n){
            for(int l=0;l<r;l++){
                 int diff=pref[r]-pref[l];
                 if(diff==k){
                    count++;
                 }
            }
            r++;
        }
     return count;
    }
    
};