class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        const int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> prev(n);
        vector<int> next(n);

        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();
        
        for(int j = n - 1; j >= 0; j--){
            while(!st.empty() && arr[st.top()] >= arr[j])
                st.pop();
            next[j] = st.empty() ? n : st.top();
            st.push(j);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (left * right * arr[i]) % mod) % mod;
        }
        return ans;
    }
};