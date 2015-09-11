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
    bool canJump(vector<int>& nums) {
        int dest = nums.size() - 1;
       // if(!dest)
        //	return true;
        if(dest < 0)
        	return false;
        int i = 0;
        int begin = i;
		while(i < dest){
			if(!nums[i]){
				for(int j = 0;j < i;j ++){
					if(nums[j] + j > i)
						i = nums[j] + j;
				}
				if(!nums[i])
					return false;
			}
			else{
				//int temp = i + nums[i];
				i = i + nums[i];
			}
		} 
		return true;
    }
    void test(){
		int A[] = {0,3,1,1,4};
		int B[] = {3,2,1,0,4};
		vector<int> vec1(A,A+3);
		vector<int> vec2(B,B+5);
		cout<<canJump(vec1)<<endl;
		cout<<canJump(vec2)<<endl; 
		
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


