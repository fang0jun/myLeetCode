class Solution {
public:
    vector<vector<int>> dirs = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    void dfs(vector<vector<char>>& board, int i, int j){
        int count = 0;
        for(const auto& dir : dirs){
            auto ni = i + dir[0];
            auto nj = j + dir[1];
            if(ni<0||nj<0||ni>=board.size()||nj>=board[0].size()) continue;
            count += board[ni][nj] == 'M';
        }

        if(count >0 ){board[i][j] = count+'0';}
        else{
            board[i][j] = 'B';
            for(const auto& dir : dirs){
                auto ni = i + dir[0];
                auto nj = j + dir[1];
                //记得去掉已经访问过的点，否则会重复互相访问无法结束
                if(ni<0||nj<0||ni>=board.size()||nj>=board[0].size()||board[ni][nj]=='B') continue;
                dfs(board, ni,nj);
            }
        }

}
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int M = board.size();
        int N = board[0].size();
        int i = click[0], j = click[1];

        if(board[i][j] == 'M') {board[i][j] = 'X'; return board;}
        if(board[i][j] == 'E') {
            dfs(board, i, j);
        }
        return board;
    }
};
