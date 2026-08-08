class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charFreq(26, 0);

        for(char c : s){ 
            charFreq[c - 'a']++; // storing frequency of each char.
        }

        for(char c : t){
            charFreq[c - 'a']--; // jo letter exist krta hai uska count kam krdo
        }

        for(int i = 0; i < 26; i++){
            if(charFreq[i] != 0)
                return false;
        }

        return true;
    }
};