class Solution {
public:
    string sortVowels(string s) {
        string vowel = "";
        for(char c : s){
            char lowerChar = tolower(c);
            if(lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' ||
                lowerChar == 'u')
                    vowel.push_back(c);
        }

        sort(vowel.begin(), vowel.end());
        int idx = 0;

        for(int i = 0; i < s.length(); i++){
            char lowerChar = tolower(s[i]);
            if(lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' ||
                lowerChar == 'u')
                s[i] = vowel[idx++];
        }

        return s;
    }
};