class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& mat, string &word, int x, int y, int idx){
        if(idx == word.length())
            return true;

        if(x < 0 || x >= m || y < 0 || y >= n)
            return false;
        
        if(mat[x][y] != word[idx])
            return false;
        
        char ori = mat[x][y];
        mat[x][y] = '#';

        bool found = 
            dfs(mat, word, x - 1, y, idx + 1) ||
            dfs(mat, word, x + 1, y, idx + 1) || 
            dfs(mat, word, x, y - 1, idx + 1) || 
            dfs(mat, word, x, y + 1, idx + 1);
        
        mat[x][y] = ori;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};