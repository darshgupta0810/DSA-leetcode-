class Solution {
public:
    bool isValid(string s) {
    stack <char> st;
    char p;
    int q=0;
    int m=0;
    if(s[0]=='}' or s[0]==')' or s[0]==']'){
      return false;
    }
    else{
      pair <char,char> p1;
      pair <char,char> p2;
      pair <char,char> p3;
      p1.first='{';
      p1.second='}';
      p2.first='(';
      p2.second=')';
      p3.first='[';
      p3.second=']';
      for(int i=0;i<s.length();i++){
        if(s[i]=='{' or s[i]=='(' or s[i]=='['){
          st.push(s[i]);
          p=st.top();
          cout<<p<<endl;
        }
        else{
          if(st.size()==0){
            m=1;
            break;
          }
          p=st.top();
          if(p==p1.first and s[i]==p1.second or p==p2.first and s[i]==p2.second or p==p3.first and s[i]==p3.second){
            st.pop();
            continue;
          }
          else{
            break;
          }
        }
      }
      if(m==0 and st.size()==0){
        return true;
      }
      else{
        return false;
      }
    }
  }
};