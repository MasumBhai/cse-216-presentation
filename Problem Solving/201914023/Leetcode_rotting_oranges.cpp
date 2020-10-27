/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Leetcode Username : tahayeasin
/// Problem Link : https://leetcode.com/problems/rotting-oranges/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int orange =0;
        int time =0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) orange++;
            }
        }

        if(orange==0) return 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>0 && grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    orange--;
                    q.push({x-1,y});
                }
                if(x<row-1 && grid[x+1][y]==1){
                    q.push({x+1,y});
                    orange--;
                    grid[x+1][y] = 2;
                }
                if(y>0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    orange--;
                    grid[x][y-1] = 2;
                }
                if(y<col-1 && grid[x][y+1]==1){
                    q.push({x,y+1});
                    orange--;
                    grid[x][y+1] = 2;
                }
            }
            time++;
            if(orange==0) return time;

        }
        return -1;


    }
};
