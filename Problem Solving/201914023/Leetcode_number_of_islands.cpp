/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Leetcode Username : tahayeasin
/// Problem Link : https://leetcode.com/problems/number-of-islands/

class Solution {
    void isIsland(vector<vector<char>>& grid , int x,int y , int row,int col){
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!='1'){
            return ;
        }
        grid[x][y] = '2';

        isIsland(grid,x+1,y,row,col);
        isIsland(grid,x-1,y,row,col);
        isIsland(grid,x,y+1,row,col);
        isIsland(grid,x,y-1,row,col);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0){
            return 0;
        }
        int col = grid[0].size();

        int island =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    isIsland(grid,i,j,row,col);
                    island++;
                }
            }
        }
        return island;
    }
};






