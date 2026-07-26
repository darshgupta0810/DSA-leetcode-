class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' or s[i]=='[' or s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                else{
                    char p=st.top();
                    st.pop();
                    if(s[i]=='}' and p!='{') return false;
                    if(s[i]==')' and p!='(') return false;
                    if(s[i]==']' and p!='[') return false;
                }
            }
        }
        if(st.empty()) return true;
        else{
            return false;
        }
    }
};