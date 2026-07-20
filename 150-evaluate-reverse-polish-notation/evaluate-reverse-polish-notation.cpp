class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto i : tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                auto a = st.top();
                st.pop();

                auto b = st.top();
                st.pop();

                if(i == "+") st.push(b + a);
                if(i == "-") st.push(b - a);
                if(i == "*") st.push(b * a);
                if(i == "/") st.push(b / a);
            }else{
                st.push(stoll(i));
            }
        }

        return st.top();
    }
};