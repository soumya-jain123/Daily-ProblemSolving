class Solution {
public:
    int solve(int i, vector<int>& parent, vector<int>& memo, vector<int>& arr){
        if(memo[i] != -1)
            return memo[i];
        
        int maxLength = 1;
        int bestParent = -1;

        for(int j = 0; j < i; j++){
            if(arr[j] % arr[i] == 0){
                int length = 1 + solve(j, parent, memo, arr);
                if(length > maxLength){
                    maxLength = length;
                    bestParent = j;
                }
            }
        }

        memo[i] = maxLength;
        parent[i] = bestParent;

        return maxLength;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> memo(n, -1);
        vector<int> parent(n, -1);

        int maxSize = 0;
        int lastIndex = 0;

        for(int i = 0; i < n; i++){
            int size = solve(i, parent, memo, nums);
            if(size > maxSize){
                maxSize = size;
                lastIndex = i;
            }
        }

        vector<int> res;
        for(int a = lastIndex; a >= 0; a = parent[a]){
            res.push_back(nums[a]);
            if(parent[a] == -1) break;
        }

        return res;
    }
};