/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Leetcode Username : tahayeasin
/// Problem Link : https://leetcode.com/problems/surrounded-regions/

class Solution {
    void findX(vector<vector<char>>& board , int i , int j,int row,int col){
        if(board[i][j]=='O'){
            board[i][j]= '$';
            if(i+1 < row) findX(board,i+1,j,row,col);
            if(i>1) findX(board,i-1,j,row,col);
            if(j+1<col) findX(board,i,j+1,row,col);
            if(j>1) findX(board,i,j-1,row,col);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row==0) return;
        int col = board[0].size();

        for(int i=0;i<row;i++){
            findX(board,i,0,row,col);
            findX(board,i,col-1,row,col);
        }

        for(int i=0;i<col;i++){
            findX(board,0,i,row,col);
            findX(board,row-1,i,row,col);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='$') board[i][j] = 'O';

            }
        }
    }
};



