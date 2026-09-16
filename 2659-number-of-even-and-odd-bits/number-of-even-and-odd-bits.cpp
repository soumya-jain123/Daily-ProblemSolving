class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0, pos = 0;

        while(n > 0){
            if(n & 1){
                if(pos % 2 == 0)
                    even++;
                else
                    odd++;
            }

            pos++;
            n >>= 1;
        }

        return {even, odd};
    }
};