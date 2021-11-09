/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//geeksforgeeks Covid Spread

class Infected {
public:
    int row, col, time;
    Infected(int r, int c, int t) {
        row = r;
        col = c;
        time = t;
    }
};
   
class Solution  {
public:

    
    int helpaterp(vector<vector<int>> hospital)
	{
	    queue<Infected> que;
	    int n = hospital.size();
	    int m = hospital[0].size();
	    int empty =0;
	    int nj,ni,timee,count =0;
	    
	    for(int i=0;i<n; i++){
	        for(int j=0; j<m ; j++){
	            if(hospital[i][j]==2)
	                que.push(Infected(i,j,0));
	            if(hospital[i][j] == 0)
	                empty++;
	        }
	    }
	    
	    while(!que.empty()){
	        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
	        count++;
	        int x = que.front().row;
	        int y =que.front().col;
	        timee = que.front().time; 
	        que.pop();
	        for(auto dir:dirs){
	             ni = x+ dir[0];
	             nj = y +dir[1];
	             
	             
	             if(ni>=0 && ni<n && nj>=0 && nj<m && hospital[ni][nj]==1){
	                 hospital[ni][nj] = 2;
	                 que.push(Infected(ni,nj,timee+1));
	  
	             }
	        }
	        
	    }
	    if(count!= ((n*m)-empty))
	        return -1;
	       
	   return timee;    
	        
	}
};
