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
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        int begin = 0;
        for(int i = 0;i < nums.size();i ++){
        	//if(!i){
        	//	sum = res = nums[i];
			//}
			//else{
				if(sum + nums[i] > 0){
					sum += nums[i];
					res = max(res,sum);
				}
				else{
					res = max(res,nums[i]);
					res = max(res,sum + nums[i]);
					if(nums[i]>0)
						sum = nums[i];
					else
						sum = 0;
				}
			//}
		}
		return res;
    }
    void test(){
		int A[] = {-2,3,1,3,-1,2,1,-5,4};
		int B[] = {-1,1,2,1};
		vector<int> vec1(A,A+9);
		vector<int> vec2(B,B+4);
		cout<<maxSubArray(vec1)<<endl; 
		cout<<maxSubArray(vec2)<<endl; 
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


