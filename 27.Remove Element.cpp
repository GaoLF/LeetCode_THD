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
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
		
		for(int i = 0;i < nums.size(); i++){
			if(nums[i] != val){
				nums[res] = nums[i];
				res ++;
			}
		}
		return res;
    }
    void test(){
    	int A[] = {2,2,9,4,5,2,3,4,6};
    	vector<int> v(A,A+9);
    	cout<<removeElement(v,2)<<endl;
    	for(int i = 0;i < v.size();i++)
    		cout<<v[i]<<" ";
    	cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


