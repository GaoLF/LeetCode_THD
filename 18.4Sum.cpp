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
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	int size = nums.size();
        vector<vector<int> > res;
		if(size < 4)
			return res;
		sort(nums.begin(),nums.end());
		for(int i = 0;i < (size - 3);i ++){
			//if(nums[i] > target)
			//	break;
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			for(int j = i + 1;j <(size - 2);j ++){
				//if(nums[i] + nums[j] > target)
				//	break;
				if(j - 1 > i && nums[j] == nums[j - 1])
					continue;
				int begin = j + 1;
				int end = size - 1;
				int goal = target - nums[i] - nums[j]; 
				while(begin < end){
					if(nums[begin] + nums[end] > goal)
						end --;
					else if(nums[begin] + nums[end] < goal)
						begin ++;
					else{
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[begin]);
						temp.push_back(nums[end]);
						res.push_back(temp);
						begin ++;
						end --;
					}
					while(begin - 1 > j && nums[begin - 1] == nums[begin])
						begin ++;
					while(end + 1 < end && nums[end] == nums[end + 1])
						end --;
				} 
			}
		}
		return res;
    }
    void test(){
		int A[] = {1,-2,-5,-4,-3,3,3,5};
		vector<int> vec(A,A+6);
		vector<vector<int> > res = fourSum(vec,-11);
		for(int i = 0;i < res.size();i ++){
			for(int j = 0;j < 4;j ++)
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


