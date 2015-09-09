#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
		for(int i = 0;i < nums.size();i ++){
			if(nums[i] < target)
				continue;
			else if(nums[i] > target){
				if(res.empty()){
					res.push_back(-1);
					res.push_back(-1);
				}
				else
					res.push_back(i - 1);
				break;
			}
			else{
				if(res.empty())
					res.push_back(i);
			}
		} 
		if(res.size() == 1)
			res.push_back(nums.size() - 1);
		if(res.empty()){
			res.push_back(-1);
			res.push_back(-1);
		}
		return res;
    }
    void test(){
		int A[] = {5,7,7,8,8,8};
		vector<int> B(A,A+6);
		vector<int> C;
		vector<int> res = searchRange(C,6);
		cout<<res[0]<<" "<<res[1]<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


