class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closetoopen = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        for (int i = 0; i < s.size(); i++) {
            if ( closetoopen.count(s[i]) ) {
                if ( !st.empty() && st.top() == closetoopen[s[i]]){
                    st.pop();
                }else {
                    return false;
                }
            }else {
            st.push(s[i]);
            }  
        }
        return st.empty();
    }
};
