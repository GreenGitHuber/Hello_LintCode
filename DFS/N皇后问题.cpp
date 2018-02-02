class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        this->columns = vector<int>(n,0);
        this->main_diag = vector<int> (2*n,0);//对角线
        this->anti_diag = vector<int>(2*n,0);//斜对角线
        vector<vector<string>> result;
        vector<int>C(n,0);
        dfs(C,result,0);
        return result;
    }
private:
    vector<int> columns;
    vector<int> main_diag;
    vector<int> anti_diag;
    
    void dfs(vector<int> &C,vector<vector<string>>&result,int row){
        const int N = C.size();
        if (row == N){
            vector<string> solution;
            for (int i = 0;i<N;i++){
                string s(N,'.');
                for (int j = 0;j<N;j++){
                    if (j==C[i])
                        s[j]='Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }
        for(int j = 0;j<N;j++){
            bool ok = columns[j]==0 &&main_diag[row+j]==0&&anti_diag[row-j+N]==0;
            if(!ok) continue;
            C[row]=j;
            columns[j]=main_diag[row+j]=anti_diag[row-j+N]=1;
            dfs(C,result,row+1);
            C[row] = 0;
            columns[j]=main_diag[row+j]=anti_diag[row-j+N]=0;
        }
        
    }
    
};
