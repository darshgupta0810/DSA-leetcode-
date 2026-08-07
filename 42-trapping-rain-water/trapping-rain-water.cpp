class Solution {
public:
    int trap(vector<int>& height) {
      if(height.size()==1){
            return 0;
        }
        else{
            int n=height.size();
            int l=height[0];
            int r=height[n-1];
            vector <int> v;
            vector <int> p;
            p.push_back(-1);
            v.push_back(-1);
            for(int i=1;i<n;i++){
                if(height[i]>l){
                    l=height[i];
                    v.push_back(-1);
                }
                else{
                    v.push_back(l);
                }
            }
            for(int i=n-2;i>=0;i--){
                if(height[i]>r){
                    p.push_back(-1);
                    r=height[i];
                }
                else{
                    p.push_back(r);
                }
            }
            reverse(p.begin(),p.end());
            int sum=0;
            for(int i=0;i<n;i++){
                if(v[i]!=-1 and p[i]!=-1){
                sum=sum+min(v[i],p[i])-height[i];
                }
            }
            return sum;
        }  
    }
};