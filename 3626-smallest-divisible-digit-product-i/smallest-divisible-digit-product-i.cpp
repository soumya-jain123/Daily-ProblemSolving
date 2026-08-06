class Solution {
public:
    int solve(int n, int t){
        int temp = n;
        int product = 1;
        while(temp > 0){
            int digit = temp % 10;
            product *= digit;
            temp /= 10;
        }

        if(product % t == 0)
            return n;
        return solve(n + 1, t);
    }
    int smallestNumber(int n, int t) {
        return solve(n, t);
    }
};