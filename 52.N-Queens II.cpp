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
    int totalNQueens(int n) {
        int res = 0;
        vector<string> temp;
        solveHelper(res,temp,0,n);
        return res;
    }
    void solveHelper(int &res,vector<string> &temp,int i,int n){
    	if(i == n){
    		res++;
    		return;
		}
    	for(int j = 0;j < n;j ++){
    		string str(n,'.');
    		str[j] = 'Q'; 
			temp.push_back(str);
    		
			if(isvalid(temp,i,j,n))
    			solveHelper(res,temp,i + 1,n);
    		temp.erase(temp.end() - 1);
		}
	}
	bool isvalid(vector<string> vec,int i,int j,int n){
		for(int m = 0;m < i;m ++){
			if(vec[m][j] == 'Q' || ((j-i+m>=0)&&(vec[m][j-(i-m)] =='Q'))||((j+i-m<n) && (vec[m][j+(i-m)]=='Q')))
				return false;
		}
		return true;
	}
    void test(){
		cout<<totalNQueens(4)<<endl;
		cout<<totalNQueens(8)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


