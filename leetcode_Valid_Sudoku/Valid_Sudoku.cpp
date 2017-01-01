class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int rowValid[10]={0};           //判断行的合法性
        int columnValid[9][10]={0};     //判断列的合法性
        int subBoardValid[9][10]={0};   //判断九宫格的合法性
        for(int i=0;i<9;i++)
        {
	    /*
		memest原型 (please type "man memset" in your shell) 

 		void *memset(void *s,  int c, size_t n); 

		memset:作用是在一段内存块中填充某个给定的值，它对较大的结构体或数组进行清零操作的一种最快方法。

	    */
            memset(rowValid,0,sizeof(rowValid));		
            for(int j=0;j<9;j++)
                if(board[i][j]!='.')
                    if(!checkValid(rowValid,board[i][j]-'0')||
                       !checkValid(columnValid[j],board[i][j]-'0')||
                       !checkValid(subBoardValid[i/3*3+j/3],board[i][j]-'0'))
                       return false;
        }
        return true;
    }
    bool checkValid(int vec[],int val)
    {
        if(vec[val] == 1)return false;
        vec[val] =1;
        return true;
    }
};