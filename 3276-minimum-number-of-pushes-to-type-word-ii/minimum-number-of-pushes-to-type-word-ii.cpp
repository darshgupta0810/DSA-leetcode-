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
        for(int i = 0; i < v.size(); i++) {
            sum += (i / 8 + 1) * v[i].first;
        }
        return sum;
    }
};