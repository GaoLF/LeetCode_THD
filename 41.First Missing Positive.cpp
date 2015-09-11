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
   	int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
		if(!size)
			return 1;
		for(int i = 0;i < size;){
			if(nums[i] > 0 && nums[i] < size && nums[i] != (i + 1) && nums[i] != nums[nums[i] - 1]){
				swap(nums[i],nums[nums[i]-1]);
			}
			else
				i ++;
		} 
		for(int i = 0;i < size;i ++){
			//cout<<nums[i]<<" ";
			if(nums[i] != (i + 1))
				return i + 1;
		}
		return size;
    }
    void test(){
		int A[] = {1,1,0};
		int B[] = {3,4,-1,1};
		vector<int> vec1(A,A+1);
		vector<int> vec2(B,B+4);
		cout<<firstMissingPositive(vec1)<<endl;
		cout<<firstMissingPositive(vec2)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


