class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> subMat[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char val = board[i][j];
                if(val == '.')
                    continue;
                
                if(row[i].find(val) != row[i].end()){
                    return false;
                }
                row[i].insert(val);

                if(col[j].find(val) != col[j].end())
                    return false;
                col[j].insert(val);

                int idx = (i / 3) * 3 + j / 3;

                if(subMat[idx].find(val) != subMat[idx].end())
                    return false;
                subMat[idx].insert(val);
            }

        }
        return true;
    }
};