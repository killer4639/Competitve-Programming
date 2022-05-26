class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n=s.length();
        int val = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(val);
                val = 0;
            }
            else {
                val = st.top() + max(2 * val, 1);
                st.pop();
            }
        }
        return val;
    }
};
