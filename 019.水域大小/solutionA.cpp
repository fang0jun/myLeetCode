class Solution {
private:
    int M ;
    int N ; 
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    int dfs(vector<vector<int>>& land,int i, int j){
        if(i >= M || i<0 || j < 0 || j >= N || visited[i][j] || land[i][j] != 0 ) return 0;

        visited[i][j] = true;
        int res = 1;
        for (const auto& dir : dirs) { // 不加引用for (const auto dir : dirs) 耗时添加近一倍
            auto ni = i + dir[0];
            auto nj = j + dir[1];
            res += dfs(land, ni, nj);
        }

        return res; 
    }
public:
    

    vector<int> pondSizes(vector<vector<int>>& land) {
         M = land.size();
         N = land[0].size(); 
        visited = vector<vector<bool>>(M, vector(N, false));
        vector<int> res;
        
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && land[i][j] == 0){
                    res.push_back(dfs(land, i, j));
                }
            }


        sort(res.begin(), res.end());
        return res;


    }
};

