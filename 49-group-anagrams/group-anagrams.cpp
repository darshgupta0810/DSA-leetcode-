class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<string,string>> s;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            s.push_back({key, str});
        }

        sort(s.begin(), s.end());

        vector<vector<string>> ans;

        vector<string> curr;
        curr.push_back(s[0].second);

        for (int i = 1; i < s.size(); i++) {
            if (s[i].first == s[i-1].first)
                curr.push_back(s[i].second);
            else {
                ans.push_back(curr);
                curr.clear();
                curr.push_back(s[i].second);
            }
        }

        ans.push_back(curr);

        return ans;
    }
};