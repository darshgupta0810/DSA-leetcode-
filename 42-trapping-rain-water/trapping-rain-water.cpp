class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==1){
            return 0;
        }
        else{
            int l=0;
            int r=n-1;
            int lm=0;
            int rm=0;
            int sum=0;
            while(l!=r){
                if(height[l]<=height[r]){
                    if(lm<height[l]){
                        lm=height[l];
                    }
                    if(lm-height[l]>=0){
                        sum=sum+lm-height[l];
                    }
                    l++;
                }

                else{
                    if(rm<height[r]){
                        rm=height[r];
                    }
                    if(rm-height[r]>=0){
                        sum=sum+rm-height[r];
                    }
                    r--;
                }

            }
            return sum;
        }
    }
};