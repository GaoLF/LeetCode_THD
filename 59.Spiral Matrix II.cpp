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
		RIGHT = 0,DOWN,LEFT,UP
	};
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n,0);
		vector<vector<int> > res(n,temp);
		int i = 0,j = 0;
		int dir = RIGHT;
		for(int num = 1;num <= n*n;){
			if(i >= 0 && j >=0 && i < n && j < n && !res[i][j]){
				res[i][j] = num;
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
		return res;
    }
    void test(){
		vector<vector<int> > res;
		res = generateMatrix(3);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<res[i].size();j++)
				cout<<res[i][j]<<" ";
			cout<<endl;
		} 
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


