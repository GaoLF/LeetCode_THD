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
	enum direction{
		RIGHT,DOWN,LEFT,UP
	};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
    	int rows = matrix.size();
		if(!rows)
			return res;
		int cols = matrix[0].size();
		if(!cols)
			return res;
		int i = 0,j = 0;
		int dir = RIGHT;
		for(int num = 0;num < rows*cols;){
			if(i >=0 && j >= 0 && i < rows && j < cols && find(res.begin(),res.end(),matrix[i][j]) == res.end()){
				res.push_back(matrix[i][j]);
				switch(dir){
					case RIGHT:j ++;break;
					case DOWN :i ++;break;
					case LEFT :j --;break;
					case UP   :i --;break;
				}
				num ++;
			}
			else{
				switch(dir){
					case RIGHT:j --;i ++;break;
					case DOWN :i --;j --;break;
					case LEFT :j ++;i --;break;
					case UP   :i ++;j ++;break;
				}
				dir = (dir+1)%4;
			}
		}
    }
    void test(){
		vector<vector<int> > res;
		int A[] = {1,2,3};
		int B[] = {4,5,6};
		int C[] = {7,8,9};
		vector<int> x;
		vector<int> vec1(A,A+3);
		vector<int> vec2(B,B+3);
		vector<int> vec3(C,C+3);
		res.push_back(vec1);
		res.push_back(vec2);
		res.push_back(vec3);
		x = spiralOrder(res);
		for(int i =0 ;i < x.size();i++ ){
			//for(int j=0;j<res[i].size();j++)
				cout<<x[i]<<" ";
			//cout<<endl;
		}
		
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


