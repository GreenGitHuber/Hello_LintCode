class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> path;
        dfs(s,path,res,0);
        return res;
    }
    void dfs(string&s,vector<string>&path,vector<vector<string>> &res,int start){
        int N = s.size();
        if(start==N){
            res.push_back(path);
            return;
        }
        for(int j = start;j<N;j++){
            if(isPalindromn(s,start,j)){
                path.push_back(s.substr(start,j-start+1));
                dfs(s,path,res,j+1);
                path.pop_back();
            }
        }
    }
    bool isPalindromn(string&s,int start,int end){
        while(start < end && s[start] == s[end]){
                start++;
                end--;
            }
           return start>=end; 
    }
};
