class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() and st.top()=='A' and s[i]=='B'){
                st.pop();
            }
            else if(!st.empty() and st.top()=='C' and s[i]=='D'){
                st.pop();
            }else
                st.push(s[i]);

        }
        return st.size();
    }
};