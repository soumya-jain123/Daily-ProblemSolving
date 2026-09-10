class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowels = 0;
        int conso = 0;

        for(char ch : s){
            if(isalpha(ch)){
                ch = tolower(ch);

                if(ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u'){
                    vowels++;
                }else
                    conso++;
            }
        }

        if(conso > 0){
            return vowels / conso;
        }
        return 0;
    }
};