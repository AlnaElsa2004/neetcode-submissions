class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
           if(ch !="+" && ch !="-" && ch !="*" && ch !="/"){
            st.push(stoi(ch));
           }else{
            int val1=st.top();
            st.pop();
            int val2=st.top();
            st.pop();
            if (ch == "+")
                    st.push(val1 + val2);

                else if (ch == "-")
                    st.push(val2 - val1);

                else if (ch == "*")
                    st.push(val1 * val2);

                else if (ch == "/")
                    st.push(val2 / val1);
           }
        }
        return st.top();
    }
};