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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
    	int size = nums.size();
    	vector<vector<int> > res;
    	//sort(nums.begin(),nums.end());
		for(int i = 0;i < size;i ++){
			if(!i){
				vector<int> temp;
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
			else{
				vector<vector<int> > res_temp;
				int num = nums[i];
				for(int j = 0;j < res.size();j ++){
					vector<int> temp = res[j];
					for(int m = 0;m <= temp.size();m ++){
						vector<int> x = temp;
						//if(m>0&&x[m-1] == num)
						//	continue;
						//if(m+1<&&x[m-1] == num)
						//	continue;
						x.insert(x.begin()+m,num);
						//if(find(res_temp.begin(),res_temp.end(),x) == res_temp.end()) 
						res_temp.push_back(x);
					}
				}
				res = res_temp;
			}
			sort(res.begin(),res.end());
			res.erase(unique(res.begin(),res.end()),res.end());
		}
		
		return res;
    }
    void test(){
		int A[] = {3,3,0,0,2,3,2};
		vector<int> V(A,A+7);
		vector<vector<int> > res;
		res = permuteUnique(V);
		for(int i = 0;i < res.size();i ++){
			for(int j = 0;j < res[i].size(); j++)
				cout<<res[i][j]<<" ";
			cout<<endl;
		}
		cout<<res.size()<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


