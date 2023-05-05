// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


/*Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Input: n = 1
Output: [["Q"]]

final code*/

class Solution {
public:
    vector<vector<string>>ans;
    bool isvalid(vector<vector<char>>&grid,int i,int j){
        // cout<<i<<j<<endl;
        for(int x=0;x<i;x++){
            if(grid[x][j]=='Q')return false;
        }
        int x=i,y=j;
        while(x>=0 and y>=0){
            if(grid[x][y]=='Q')return false;
            x--;y--;
        }
        x=i,y=j;
        while(x>=0 and y<grid.size()){
            if(grid[x][y]=='Q')return false;
            x--;y++;
        }
        // cout<<i<<j<<endl;
        return true;
    }
    void helper(vector<vector<char>>grid,int i){
        // cout<<i<<endl;
        if(i==grid.size()){
            vector<string>temp;
            for(int x=0;x<grid.size();x++){
                string s="";
                for(auto it:grid[x]){
                    s+=it;
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<grid.size();col++){
            if(isvalid(grid,i,col)){
                grid[i][col]='Q';
                helper(grid,i+1);
                grid[i][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        helper(grid,0);
        return ans;
    }
};
