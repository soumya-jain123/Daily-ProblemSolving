class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;

        for(int row = 0; row < numRows; row++){
            vector<int> arr; // to store numbers in current array

            for(int i = 0; i <= row; i++){ // each row contain elements equal to row number
                if(row == i || i == 0){ // last anf first number is alwyas 1
                    arr.push_back(1);
                }
                else{
                    arr.push_back(mat[row - 1][i - 1] + mat[row - 1][i]);
                }
            }
            mat.push_back(arr);
        }

        return mat;
    }
};