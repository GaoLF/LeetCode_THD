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
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(!size)
        	return -1;
        	
		if(target >= nums[0]){
			for(int i = 0;i < size; i ++){
				if(target == nums[i])
					return i;
				if(i + 1 < size && nums[i + 1] < nums[i])
					return -1;
			}
		} 
		else{
			for(int i = (size - 1);i >= 0; i --){
				if(target == nums[i])
					return i;
				if(i - 1 >= 0 && nums[i - 1] > nums[i])
					return -1;
			}	
		}
		return -1;
    }
    void test(){
		int A[] = {4,5,6,7,0,1,2};
		vector<int> x(A,A+7);
		cout<<search(x,1)<<endl;
		cout<<search(x,6)<<endl;
		cout<<search(x,0)<<endl;
		cout<<search(x,3)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


