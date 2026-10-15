class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i = 0; i < s.size(); i++){
            int cost = min(s[i] - 'a', 26 - (s[i] - 'a'));

            if(cost <= k){
                k -= cost;
                s[i] = 'a';
            }else{
                s[i] -= k;
                break;
            }
        }
        return s;
    }
};