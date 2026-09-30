class Solution {
public:
bool isvalid(int i,int j,int d,vector<vector<char>>& board){
 
          
                for (int j=0;j<9;j++){
                   if(board[i][j]=='.')continue;
                   else {
                    if(board[i][j]=='0'+d)return false;
                   }
                
                }
            
            //checking columns

        
                   for (int i=0;i<9;i++){
                   if(board[i][j]=='.')continue;
                   else {
                    if(board[i][j]=='0'+d)return false;
                   }
                
                }
                int sr = (i / 3) * 3;
int sc = (j / 3) * 3;

for(int i=sr;i<sr+3;i++){
    for(int j=sc;j<sc+3;j++)
    {

if(board[i][j]==d+'0')return false;
    }
}

        return true;    
}
bool solve(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(int d=1;d<=9;d++){
                    if(isvalid(i,j,d,board)){
                          board[i][j]='0'+d;
                          if(solve(board))return true;
                          board[i][j]='.';
                    }
             
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};