class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        int moves = 0;

        while(i < j){
            int k = j;

            while(k > i && s[k] != s[i]){
                k--;
            }
            if(k == i){
                swap(s[i], s[i + 1]);
                moves++;
            }else{
                while(k < j){
                    swap(s[k], s[k + 1]);
                    k++;
                    moves++;
                }
                i++;
                j--;
            }
        }

        return moves;
    }
};