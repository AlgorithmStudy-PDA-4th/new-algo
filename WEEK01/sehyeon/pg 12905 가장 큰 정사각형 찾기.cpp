#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int field[1000][1000];

int solution(vector<vector<int>> board) {
    int ans = 0;
    if(board.size()==1 && board[0].size()==1) {
        if(board[0][0]==1) return 1;
        else return 0;
        }
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(i==0 || j==0) {
                field[i][j] = board[i][j];
                continue;
            }
            if(board[i][j]==1) {
                field[i][j] = min(field[i-1][j-1], min(field[i][j-1], field[i-1][j])) + 1;
                ans = max(ans, field[i][j]);
            }
        }
    }
    return ans * ans;
}
