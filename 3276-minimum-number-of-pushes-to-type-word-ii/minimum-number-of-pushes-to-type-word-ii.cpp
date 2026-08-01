class Solution {
public:
    int minimumPushes(string word) {
        set <char> st;
        for(char x:word){
            st.insert(x);
        } 
        map<char,int> freq;
        for(char x:word){
            freq[x]++;
        } 
        vector <pair<int,char>> v;
        for (auto it : freq) {
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(),v.rend());
        int p=0;
        int q=8;
        int j=1;
        int sum=0;
        for(int i=0;i<st.size();i++){
            if(p>=q){
                q=q+8;
                j=j+1;
            }
            sum=sum+j*v[i].first;
            p=p+1;
        }
        return sum;
    }
};