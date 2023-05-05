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
