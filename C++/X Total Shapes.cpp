/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//geeksforgeeks// X Total Shapes

class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int num =0;
    int xShape(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        for(int i =0 ;i<row;i++ ){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='X'){
                    num++;
                    dsf(grid,i,j);
                }
            }
        } return num;
    }
    void dsf(vector<vector<char>> &grid,int i,int j){
        int row = grid.size();
        int col = grid[0].size();
        int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        grid[i][j]='0';
        for(auto dir:dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni<row && nj>=0 && nj<col && grid[ni][nj]=='X')
                dsf(grid,ni,nj);
        }
    }
};