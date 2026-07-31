class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};
        vector<pair<string,string>> s;
        int n=strs.size();

        for (int i=0;i<n;i++) {
            string s1 = strs[i];
            string s2 = strs[i];
            sort(s1.begin(), s1.end());
            s.push_back({s1, s2});
        }

        sort(s.begin(), s.end());

        vector<vector<string>> ans;

        vector<string> curr;
        curr.push_back(s[0].second);

        for (int i = 0; i < s.size()-1; i++) {
            if (s[i].first == s[i+1].first)
                curr.push_back(s[i+1].second);
            else {
                ans.push_back(curr);
                curr.clear();
                curr.push_back(s[i+1].second);
            }
        }

        ans.push_back(curr);

        return ans;
    }
};