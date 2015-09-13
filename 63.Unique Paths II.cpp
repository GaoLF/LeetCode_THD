#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<stack> 
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if(!rows)
        	return 0;
		int cols = obstacleGrid[0].size();
		if(!cols)
			return 0;
		vector<int> temp(cols,0); 
		vector<vector<int> > res(rows,temp);
		for(int i = 0;i < rows;i ++){
			for(int j = 0;j < cols;j ++){
				if(!obstacleGrid[i][j]){
					if(!i && !j)
						res[i][j] = 1;
					else if(i > 0 && j > 0){
						res[i][j] = res[i-1][j] + res[i][j-1];
					}
					else if(i > 0)
						res[i][j] = res[i-1][j];
					else
						res[i][j] = res[i][j-1];
				}
			}
		}
		return res[rows - 1][cols - 1];
    }
    void test(){
		int A[] = {1,0,0};
		int B[] = {0,1,0};
		int C[] = {0,0,0};
		vector<int> vec1(A,A+2);
		vector<int> vec2(B,B+3);
		vector<int> vec3(C,C+3);
		vector<vector<int> > res;
		res.push_back(vec1);
		//res.push_back(vec2);
		//res.push_back(vec3);
		cout<<uniquePathsWithObstacles(res)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


