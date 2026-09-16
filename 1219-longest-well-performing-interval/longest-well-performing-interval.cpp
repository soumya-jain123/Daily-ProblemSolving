class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(hours[i] > 8){
                prefix[i + 1] = prefix[i] + 1;
            }else
                prefix[i + 1] = prefix[i] - 1;
        }

        stack<int> st;

        for(int i = 0; i < n; i++){
            while(st.empty() || prefix[i]<prefix[st.top()])
                st.push(i);
        }

        int ans = 0;

        for(int i = n; i >= 0; i--){
            while(!st.empty() && prefix[i] > prefix[st.top()]){
                ans = max(ans, i - st.top());
                st.pop();
            }
        }

        return ans;
    }
};