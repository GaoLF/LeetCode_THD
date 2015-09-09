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
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
		int i;
		if(!size)
			return ;
			
		for(i = size - 1;i > 0;i --){
			if(nums[i - 1] < nums[i])
				break;
		}
		if(i - 1 >= 0 && nums[i - 1] < nums[i]){
			for(int j = size - 1;j >= 0;j --){
				if(nums[j] > nums[i - 1]){
					swap(nums[j],nums[i - 1]);
					break;
				}
			}
		}
		sort(nums.begin() + i, nums.end());
		return ;
    }
    void test(){
		int A[] = {1,2,3};
		int B[] = {3,2,1};
		int C[] = {1,1,5};
		vector<int> a(A,A+1);
		vector<int> b(B,B+3);
		vector<int> c(C,C+3);
		nextPermutation(a);
		nextPermutation(b);
		nextPermutation(c);
		for(int i = 0;i < a.size(); i ++)
			cout<<a[i]<<" ";
		cout<<endl; 
		for(int i = 0;i < b.size(); i ++)
			cout<<b[i]<<" ";
		cout<<endl;
		for(int i = 0;i < b.size(); i ++)
			cout<<c[i]<<" ";
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


