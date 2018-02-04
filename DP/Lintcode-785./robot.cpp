#include "stdafx.h"
#include <vector>
#include <iostream>
#include<algorithm>  

using namespace std;
class Solution {
public:
	/**
	* @param nums: the n x m grid
	* @return: the maximum weighted sum
	*/
	int dfs(vector<vector<int>> &nums, int row, int col) {
		int end_row = nums.size() - 1;
		int end_col = 0;

		//end
		if (row == end_row && col == end_col) {
			return nums[row][col];
		}

		//到了最下面的一行
		if (row == end_row) {
			int ret = 0;
			for (int i = 0; i <= col; i++) {
				ret += nums[row][i];
			}
			return ret;
		}
   int main()
{
	vector<vector<int>> nums;
	vector<int> v0 = { 1,2,3,4 };
	vector<int> v1 = { 3,5,6,7 };
	vector<int> v2 = { 9,10,1,2 };
	vector<int> v3 = { 4,4,5,5 };

	nums.push_back(v0);
	nums.push_back(v1);
	nums.push_back(v2);
	nums.push_back(v3);

	Solution s;
	cout << s.maxWeight(nums) << endl;


	system("pause");
    return 0;
}

		//到了最左边的一列
		if (col == end_col) {
			int ret = 0;
			for (int i = row; i <= end_row; i++) {
				ret += nums[i][0];
			}
			return ret;
		}

		//进入下一波递归
		return   max(nums[row][col]+ dfs(nums, row + 1, col), nums[row][col]+ dfs(nums, row, col - 1) );
	}


	int maxWeight(vector<vector<int>> &nums) {
		// write your code here
		int begin_row = 0;
		int begin_col = nums[0].size() - 1;
		return dfs(nums, begin_row, begin_col);
	}
  
  ####solution2 ：pass
       int dfs(vector<vector<int>> &nums,vector<vector<int>> &table, int row, int col) {
        int end_row = nums.size() - 1;
		int end_col = 0;
		
        if(table[row][col]>0){
            return table[row][col];
         }
    		//end
    		if (row == end_row && col == end_col) {
    			return table[row][col]=nums[row][col];
    		}
    
    		//到了最下面的一行
    		if (row == end_row) {
    			return table[row][col]=nums[row][col]+ dfs(nums,table, row, col - 1);
    		}

    		//到了最左边的一列
    		if (col == end_col) {
    			return table[row][col]=nums[row][col]+ dfs(nums,table, row + 1, col);
    		}
    
    		//进入下一波递归
    		table[row][col]=max(nums[row][col]+ dfs(nums,table, row + 1, col), nums[row][col]+ dfs(nums,table, row, col - 1) );
	
	return table[row][col];
     }


	int maxWeight(vector<vector<int>> &nums) {
		// write your code here
		int rows=nums.size();
        int cols = nums[0].size();
        int begin_row = 0;
		int begin_col = nums[0].size() - 1;
        vector<vector<int>> table;
         //初始化
         for(int i=0;i<rows;i++){
             vector<int> r;
             for(int j=0;j<cols;j++){
                r.push_back(-1);
             }
             table.push_back(r);
         }
        return dfs(nums,table, begin_row, begin_col);
	}
};
