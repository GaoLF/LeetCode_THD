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
	//���������py���ԣ���c++��ʱ 
	//��ʵ����û��ֻ�ǻ�Ӧ���Ż�����һ����findӦ��ȥ��
	//��������ֵͬ������ 
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int length = nums.size();
		for(int i = 0; i < length - 2;i++){
			if(nums[i] > 0)
				break;
			int front = i + 1;
			int back = length -1;
			int target = -nums[i];
			
			while(front < back){
				if(nums[front] + nums[back] > target)
					back -- ;
				else if(nums[front] + nums[back] < target)
					front ++;
				else{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[front]);
					temp.push_back(nums[back]);
					//if(find(res.begin(),res.end(),temp)==res.end())
					res.push_back(temp);
					//front ++;
					//back --;
					while(front < back && nums[front] == temp[1])
						front ++;
					while(front < back && nums[back] == temp[2])
						back --;
				}
			} 
			while(i + 1 < length && nums[i + 1] == nums[i])
				i ++; 
		} 
		return res;
    }
    void test(){
		vector<vector<int> > res;
		int A[] = {-1,0,1,2,-1,-4};
		vector<int> input(A,A+6);
		res = threeSum(input);
		for(int i = 0;i < res.size(); i++){
			for(int j = 0; j < res[i].size();j ++)
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


