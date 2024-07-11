class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int start =0,end =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                start = st.top()+1;
                end = i;
                reverse(s.begin()+start,s.begin()+end);
                st.pop();
            }
        }
        string ans = "";
        for(auto it: s){
            if(it!=')' && it!='('){
                ans+= it;
            }
        }
        return ans;

    }
};