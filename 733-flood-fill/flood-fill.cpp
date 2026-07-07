class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        queue<pair<int, int>> q;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int oldColor = image[sr][sc];
        q.push({sr,sc});

        image[sr][sc] = color;

        while(!q.empty()){
            pair<int , int> front = q.front();
            int x = front.first;
            int y = front.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < image.size() && ny < image[0].size() && image[nx][ny] == oldColor){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};