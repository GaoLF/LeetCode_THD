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
    int removeDuplicates(vector<int>& nums) {
        int position = 0;
        int last_num = 0;
        
		for(int i = 0;i < nums.size();i ++){
			if(!i){
				last_num = nums[i];
				position ++;
			}	
			else{
				if(nums[i] != last_num){
					last_num = nums[i];
					nums[position] = nums[i];
					position ++;
				}
			} 	
		}
		
		return position;
    }
    void test(){
    	int a[] = {1,1,2};
		vector<int> v(a,a+3);
		cout<<removeDuplicates(v)<<endl<<endl;
		
		for(int i = 0;i < v.size(); i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


