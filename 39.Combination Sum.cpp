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
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
		vector<int> temp;
		sort(candidates.begin(),candidates.end());
		sumHelper(candidates,target,temp,res,0); 
    	return res;
	}
    void sumHelper(vector<int>& can,int tar,vector<int> &temp,vector<vector<int> >&res,int i){
    	if(i >= can.size())
			return; 
    	if(can[i] == tar){
    		temp.push_back(tar);
    		res.push_back(temp);
    		temp.erase(temp.end()-1);
		}
		else if(can[i] < tar){
			sumHelper(can,tar,temp,res,i+1);
			int size = temp.size();
			temp.push_back(can[i]);
			sumHelper(can,tar-can[i],temp,res,i);
			temp.erase(temp.begin()+size); 
		}
	}
    void test(){
		int A[] = {8,7,4,3};
		vector<int> B(A,A+4);
		vector<vector<int> > res = combinationSum(B,11);
		for(int i = 0;i < res.size();i ++){
			for(int j = 0;j < res[i].size();j ++)
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


