/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Leetcode Username : tahayeasin
/// Problem Link : https://leetcode.com/problems/word-search/


class Solution {
    bool wordSearch(vector<vector<char>>& grid , int x,int y , int row,int col,string word,int count){
        if(count==word.size()){
            return true;
        }
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!= word[count]){
            return false;
        }
        char temp = grid[x][y];
        grid[x][y] = '$';

        bool isPossible =wordSearch(grid,x+1,y,row,col,word,count+1) ||
        wordSearch(grid,x-1,y,row,col,word,count+1) ||
        wordSearch(grid,x,y+1,row,col,word,count+1) ||
        wordSearch(grid,x,y-1,row,col,word,count+1) ;

        grid[x][y] = temp;
        return isPossible;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(row==0) return false;
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j]){
                    bool isPossible = wordSearch(board,i,j,row,col,word,0);
                    if(isPossible==true){
                        return true;
                    }
                }
            }
        }
        return false;


    }
};


