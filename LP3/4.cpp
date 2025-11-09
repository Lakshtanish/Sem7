//n - queens
#include <iostream>
#include <vector>
using namespace std;

class NQueen{
    private:
        vector<string> board;
        int queenRow;
        int queenCol;

    public:
        NQueen(int n, int qR, int qC){
            board.assign(n, string(n, '.'));
            this->queenCol = qC;
            this->queenRow = qR;
            board[qR][qC] = 'Q';
        }

        bool isSafe(int row, int col){
            int n = board.size();
            if(row == queenRow || col == queenCol) return false;

            //horizontal
            for(int i = 0; i < n; i++){
                if(i == col) continue;
                if(board[row][i] == 'Q'){
                    return false;
                }
            }

            //vertical
            for(int i = 0; i < n; i++){
                if(i == row) continue;
                if(board[i][col] == 'Q'){
                    return false;
                }
            }

            // top -right diagnol
            for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }

            // top-left
            for(int i = row-1, j = col - 1; i >= 0 && j >= 0; i--, j--){
                if(board[i][j] == 'Q') return false;
            }

            //bottom-right
            for(int i = row+1, j = col + 1; i < n && j < n; i++, j++){
                if(board[i][j] == 'Q') return false;
            }

            //bottom-left
            for(int i = row+1, j = col-1; i < n && j >= 0; i++, j--){
                if(board[i][j] == 'Q') return false;
            }

            return true;
        }

        bool solve(int row){
            if(row >= board.size()) return true;
            if(row == queenRow){
                return solve(row+1);
            }
            for(int col = 0; col < board.size(); col++){
                if(isSafe(row, col)){
                    board[row][col] = 'Q';
                    if(solve(row + 1) == true){
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
            return false;
        }

        void printBoard(){
            int n = board.size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout<<board[i][j]<<"\t";
                }
                cout<<"\n";
            }
        }
};

int main(){
    //creating board with first queen already placed
    NQueen q(4, 0, 0);
    q.solve(0);
    q.printBoard();
}