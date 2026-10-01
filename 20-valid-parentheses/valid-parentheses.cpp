class Solution {
public:
    bool compare(char a, char b){
        if((b == ')' && a == '(')
         ||( b == ']' && a == '[')
         ||(b == '}' && a == '{'))
            return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(compare(top, ch)){
                        st.pop();
                    }else
                        return false;
                }else return false;
            }
        }
        if(st.empty())
        return true;
        else return false;
    }
};