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
    vector<vector<int> > permute(vector<int>& nums) {
    	int size = nums.size();
    	vector<vector<int> > res;
		for(int i = 0;i < size;i ++){
			if(!i){
				vector<int> temp;
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
			else{
				vector<vector<int> > res_temp;
				int num = nums[i];
				for(int j = 0;j < res.size();j ++){
					vector<int> temp = res[j];
					for(int m = 0;m <= temp.size();m ++){
						vector<int> x = temp;
						x.insert(x.begin()+m,num);
						res_temp.push_back(x);
					}
				}
				res = res_temp;
			}
		}
		return res;
    }
    void test(){
		int A[] = {1,2,3,4};
		vector<int> V(A,A+4);
		vector<vector<int> > res;
		res = permute(V);
		for(int i = 0;i < res.size();i ++){
			for(int j = 0;j < res[i].size(); j++)
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


