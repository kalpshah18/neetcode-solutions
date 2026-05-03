class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                if(tokens[i] == "+") op1 += op2;
                if(tokens[i] == "-") op1 -= op2;
                if(tokens[i] == "*") op1 *= op2;
                if(tokens[i] == "/") op1 /= op2;
                st.push(op1);
            } else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
